using namespace clang;
using namespace ento;

class DivZeroChecker : public Checker< check::PreStmt<BinaryOperator> > {
  mutable OwningPtr<BuiltinBug> BT;
  void reportBug(const char *Msg,
                 ProgramStateRef StateZero,
                 CheckerContext &C) const ;
public:
  void checkPreStmt(const BinaryOperator *B, CheckerContext &C) const;
};  

void DivZeroChecker::reportBug(const char *Msg,
                               ProgramStateRef StateZero,
                               CheckerContext &C) const {
  if (ExplodedNode *N = C.generateSink(StateZero)) {
    if (!BT)
      BT.reset(new BuiltinBug("Division by zero"));

    BugReport *R = new BugReport(*BT, Msg, N);
    bugreporter::trackNullOrUndefValue(N, bugreporter::GetDenomExpr(N), *R);
    C.emitReport(R);
  }
}

void DivZeroChecker::checkPreStmt(const BinaryOperator *B,
                                  CheckerContext &C) const {
  BinaryOperator::Opcode Op = B->getOpcode();
  if (Op != BO_Div && Op != BO_Rem &&
      Op != BO_DivAssign && Op != BO_RemAssign)
    return;
  if (!B->getRHS()->getType()->isScalarType())
    return;
  SVal Denom = C.getState()->getSVal(B->getRHS(), C.getLocationContext());
  Optional<DefinedSVal> DV = Denom.getAs<DefinedSVal>();
  if (!DV)
    return;
  ConstraintManager &CM = C.getConstraintManager();
  ProgramStateRef stateNotZero, stateZero;
  llvm::tie(stateNotZero, stateZero) = CM.assumeDual(C.getState(), *DV);
  if (!stateNotZero) {
    assert(stateZero);
    reportBug("Division by zero", stateZero, C);
    return;
  }
  bool TaintedD = C.getState()->isTainted(*DV);
  if ((stateNotZero && stateZero && TaintedD)) {
    reportBug("Division by a tainted value, possibly zero", stateZero, C);
    return;
  }
  C.addTransition(stateNotZero);
}

void ento::registerDivZeroChecker(CheckerManager &mgr) {
  mgr.registerChecker<DivZeroChecker>();
}

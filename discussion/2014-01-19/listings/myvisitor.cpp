class MyVisitor : public RecursiveASTVisitor<MyVisitor> {
public:
  explicit MyVisitor(ASTContext *Context)
    : Context(Context) {}

  bool VisitEnumDecl(EnumDecl *EDecl) {
    if (EDecl->getQualifiedNameAsString().find("NS::") == 0) {
      FullSourceLoc FullLocation = Context->getFullLoc(EDecl->getLocStart());
        if (FullLocation.isValid())
          llvm::outs() << "Found declaration at "
                       << FullLocation.getSpellingLineNumber() << ":"
                       << FullLocation.getSpellingColumnNumber() << "\n";
    }
    return true;
  }

private:
  ASTContext *Context;
};

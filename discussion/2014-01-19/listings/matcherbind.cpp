StatementMatcher LoopMatcher =
    forStmt(hasLoopInit(declStmt(hasSingleDecl(varDecl(
            hasInitializer(integerLiteral(equals(0)))))))).bind("forLoop");

class LoopPrinter : public MatchFinder::MatchCallback {
public :
    virtual void run(const MatchFinder::MatchResult &Result) {
        if (const ForStmt *FS = Result.Nodes.getNodeAs<clang::ForStmt>("forLoop"))
            FS->dump();
    }
};

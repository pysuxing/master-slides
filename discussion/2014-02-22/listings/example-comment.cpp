StatementMatcher LoopMatcher = 
/* M<Stmt> */ forStmt(                   // M<ForStmt>
/* M<ForStmt> */hasLoopInit(             // M<Stmt>
/* M<Stmt> */     declStmt(              // M<DeclStmt>
/* M<DeclStmt> */   hasSingleDecl(       // M<Decl>
/* M<Decl> */	      varDecl(	         // M<VarDecl>
/* M<VarDecl> */        hasInitializer(  // M<Expr>
/* M<Stmt> */	          integerLiteral(// M<IntegerLiteral>
/* M<IntegerLiteral> */     equals(
                              0)))))))).bind("forLoop")

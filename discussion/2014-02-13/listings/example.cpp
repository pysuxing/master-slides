StatementMatcher LoopMatcher = 
  forStmt(
    hasLoopInit(
      declStmt(
	hasSingleDecl(
	  varDecl(
            hasInitializer(
	      integerLiteral(
		equals(
                  0)))))))).bind("forLoop")

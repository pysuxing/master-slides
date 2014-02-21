StatementMatcher LoopMatcher = 
  forStmt(			// Node
    hasLoopInit(		// Traversal
      declStmt(			// Node
	hasSingleDecl(		// Traversal
	  varDecl(		// Node
            hasInitializer(	// Traversal
	      integerLiteral(	// Node
		equals(		// Narrowing
		  0)))))))).bind("forLoop")

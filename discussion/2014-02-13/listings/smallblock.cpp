AST_MATCHER_P(CompoundStmt,
	      statementCountLessThan,
	      unsigned, N) {
   return Node.size() < N;
}

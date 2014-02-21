// Returns a new FrontendActionFactory for a given type. 
// T must derive from clang::FrontendAction.
template<typename T >
FrontendActionFactory * newFrontendActionFactory ();
// Returns a new FrontendActionFactory for any type that
// provides an implementation of newASTConsumer(). 
// FactoryT must implement: ASTConsumer *newASTConsumer().
template<typename FactoryT >
FrontendActionFactory * newFrontendActionFactory (
    FactoryT *ConsumerFactory,
    SourceFileCallbacks *Callbacks=NULL)

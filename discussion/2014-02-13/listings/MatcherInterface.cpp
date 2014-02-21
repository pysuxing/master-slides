template <typename T> class MatcherInterface {
public:
  bool matches(const T &Node,
	       ASTMatchFinder *Finder,
	       BoundNodesTreeBuilder *Builder);
};
template <typename T> class Matcher {
public:
  Matcher(MatcherInterface<T> *Implementation)
    : Implementation(Implementation) {}
private:
   MatcherInterface<T>* Implementation;
};


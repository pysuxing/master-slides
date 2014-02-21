template <typename Base>
class ImplicitCastMatcher : public MatcherInterface<T> {
public:
  ImplicitCastMatcher(const Matcher<Base> &From)
    : From(From) {}
  bool matches(const T &Node,
	       ASTMatchFinder *Finder,
	       BoundNodesTreeBuilder *Builder)const {
    return From.matches(Node, Finder, Builder);
  }
private:
  const Matcher<Base> From;
};

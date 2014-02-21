template <typename T>
class Matcher {
public:
  ...
  bool matches(const T &Node,
	       ASTMatchFinder *Finder,
	       BoundNodesTreeBuilder *Builder);
  ...
};

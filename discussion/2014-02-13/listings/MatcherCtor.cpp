template <typename T>
class Matcher {
public:
  template <typename From>
  Matcher(const Matcher<From> &Other,
	  ... ) // meta-prog stuff
    : Implementation(
	new ImplicitCastMatcher<From>(Other)) {}
private:
   MatcherInterface<T>* Implementation;
};

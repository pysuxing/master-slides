parallelSum :: Monoid a => [a] -> a
parallelSum v = fold mappend v
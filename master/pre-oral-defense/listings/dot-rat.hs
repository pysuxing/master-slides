dot :: Numeric -> [a] -> [a] -> a
dot v1 v2 = fold + (zipWith * v1 v2)
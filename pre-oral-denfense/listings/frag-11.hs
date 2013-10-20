dot :: [Float] -> [Float] -> Float
res v1 v2 = fold + (map (uncurry *) (zip v1 v2))
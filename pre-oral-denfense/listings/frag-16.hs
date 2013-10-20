foo :: [Float] -> [Float] -> [Float]
foo v1 v2 = reverse (zipWith + v1 v2)

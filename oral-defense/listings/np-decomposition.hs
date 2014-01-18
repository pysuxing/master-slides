npVector :: [[Float]]
npVector = map (\s -> [s...s+10]) [0...10]

npSum :: [[Float]] -> [Float]
npSum npv = map (fold +) npv

nps :: [Float]
nps = npSum npVector
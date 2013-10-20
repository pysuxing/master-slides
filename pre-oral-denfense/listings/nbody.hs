solveNBodyOneStep :: Float -> [Cell] -> [Cell]
solveNBodyOneStep t cells = 
  zipWith3 makeCell masses newPositions newVelocities
  where
    positions = map position cells -- original positions
    velocities = map velocity cells -- original velocity
    calcSingleAcc c1 c2 =
      (g * mass c2) / (squre (position c1 - position c2) )    
    calcAccelerate cell = 
      fold + (map (calcSingleAcc cell) cells)
    accelerates = map calcAccelerate cells -- accelerate
    newVeciloties =               -- new velocity
      zipWith (\v a -> v + a * t) velocities accelerates
    newPositions =                -- new positions
      zipWith (\p v -> p + v * t) positions velocities

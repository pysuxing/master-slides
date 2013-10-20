matrixMul matA matB =
  [ [dot row col | col <- transpose matB] 
  | row <- matA]
  where
    dot v1 v2 = 
      fold + (zipWith * v1 v2)
    transpose matrix = 
      newMatrix (content matrix) (flip (indexer matrix))
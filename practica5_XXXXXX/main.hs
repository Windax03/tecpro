Import Turtle
Import SVG

tplot :: Turtle −> String −> [Position]
tplot turtle [] = [getPos turtle]
tplot turtle (x:xs)
  | x == '>'  = getPos turtle : tplot (forward turtle) xs
  | x == '+'  = tplot (turnRight turtle) xs
  | x == '-'  = tplot (turnLeft turtle) xs
  | otherwise = tplot turtle xs
  where getPos (_, _, pos, _) = pos

main = do  
    figura = tplot (1,90,(0,0),90) ">+>+>+>+"
    savesvg "cuadrado" figura

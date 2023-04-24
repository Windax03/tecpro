-- Solucion recursiva, calculo absoluto
gregoryleibnitz = aux 0
  where
    aux i = 4*(num i/den i) : aux (i+1)
    num x = fromIntegral ((-1)^x)
    den x = fromIntegral (2*x+1)

-- Solucion recursiva, calculo incremental
gregoryleibnitz' = aux 4 1
  where
    aux n d = (n/d) : aux (-n) (d+2)

-- Solucion con listas, generadas con map
gregoryleibnitz'' = zipWith (/) numl denl
  where
    num x = 4*(-1)^x
    numl  = map num [0..]
    den x = 2*x+1
    denl  = map den [0..]

-- Solucion con listas, generadas con map y secciones
gregoryleibnitz''' = zipWith (/) numl denl
  where
    numl  = map ((4*).((-1)^)) [0..]
    denl  = map ((1+).(2*)) [0..]

-- Solucion con listas, generadas por comprension
gregoryleibnitz'''' = zipWith (/) numl denl
  where
    numl = [ 4*(-1)^i | i <- [0..] ]
    denl = [ 2*i+1    | i <- [0..] ]

-- Solucion con generadores
gregoryleibnitz''''' = zipWith (/) (cycle [4,-4]) [1,3..]

approxPiTer :: Int -> Double
approxPiTer n = sum $ take n gregoryleibnitz

approxPiTol :: Double -> Double
-- approxPiTol tol = sum $ takeWhile (\x -> abs x > t) gregoryleibnitz
approxPiTol tol = sum $ takeWhile ((>tol).abs) gregoryleibnitz

main = do
  print $ take 5 gregoryleibnitz
  print $ take 5 gregoryleibnitz'
  print $ take 5 gregoryleibnitz''
  print $ take 5 gregoryleibnitz'''
  putStrLn "Ter:"
  print $ approxPiTer (10^2)
  print $ approxPiTer (10^3)
  print $ approxPiTer (10^4)
  print $ approxPiTer (10^5)
  putStrLn "Tol:"
  print $ approxPiTol 1e-2
  print $ approxPiTol 1e-3
  print $ approxPiTol 1e-4
  print $ approxPiTol 1e-5

module Main where

-- Para medir el tiempo de ejecucion
import System.CPUTime

main = do
  print $ primesn 10
  timedRun primes
  timedRun primes'
  timedRun primes''
  timedRun primes'''

-- Calcula el tiempo necesario para calcular N primos
-- La funcion a testear se pasa como parametro
timedRun :: [Integer] -> IO ()
timedRun f = do
  t0 <- getCPUTime
  print $ last (take 5000 f)
  t1 <- getCPUTime
  -- Si, son _picoseconds_
  putStr "Time: "
  print $ div (t1-t0) 1000000000

primesn n = take n primes

-- Metodos directos
prime n   = all ((/= 0).mod n) [2..n-1]
primes    = 1 : 2 : [ x | x <- [3,5..], prime x ]

prime' n  = all ((/= 0).mod n) [2..(div n 2)]
primes'   = 1 : 2 : [ x | x <- [3,5..], prime' x ]

prime'' n = all ((/= 0).mod n) [2..(round.sqrt.fromInteger) n]
primes''  = 1 : 2 : [ x | x <- [3,5..], prime'' x ]

-- Criba de Eratostenes
primes''' = 1 : 2 : sieve [3,5..]
  where
    sieve [] = []
    -- El primero se considera primo
    -- Se buscan mas primos en la lista resultante de
    -- eliminar sus multiplos de la original
    sieve (p:xs) = p : sieve [x | x<-xs, mod x p /= 0]

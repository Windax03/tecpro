-- Elige una implementacion para el calculo de primos
primes = 1 : sieve[2..]
  where
    sieve (p:xs) = p : sieve [x | x <- xs, x `mod` p /= 0]

primesn n = take n primes

-- goldbach :: Int -> [ (Int,Int) ]
goldbach n = [(x, y) | x <- primes', x <= n `div` 2, y <- primes', x + y == n]
  where
    primes' = takeWhile (<= n) primes

n = 74
main = do
  print $ n
  print $ goldbach n


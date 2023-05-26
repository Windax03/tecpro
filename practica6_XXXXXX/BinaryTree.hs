--------------------------------------------------------------------------------
-- File:   BinaryTree.hs
-- Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
-- Date:    mayo 2023
-- Coms:    Fichero que almacena la implementación de las funciones necesarias para
--          crear y interpretar arboles.
--------------------------------------------------------------------------------

module BinaryTree where

import Data.List (sort)

-----------------------------PARTE 1--------------------------------------------

data BinaryTree a = Empty | Leaf a | Tree a (BinaryTree a) (BinaryTree a) 

empty :: BinaryTree a
empty = Empty

leaf :: a -> BinaryTree a
leaf x = Leaf x

tree :: a -> (BinaryTree a) -> (BinaryTree a) -> (BinaryTree a)
tree x lc rc = Tree x lc rc

size :: BinaryTree a -> Integer
size Empty = 0
size (Leaf _) = 1
size (Tree _ lc rc) = 1 + size lc + size rc

nivel :: Integer -> String
nivel 0 = ""
nivel x = ("   ") ++ (nivel(x-1))

instance Show a => Show (BinaryTree a) where
  show t = showLines t 0
    where
      showLines Empty x = "<>"
      showLines (Leaf y) x = show y
      showLines (Tree y lc rc) x = show y ++ ['\n'] ++ nivel x ++ "|- " ++ showLines lc (x+1) ++ ['\n'] ++ nivel x ++ "|- " ++ showLines rc (x+1)

-----------------------------PARTE 2--------------------------------------------

add :: Ord a => BinaryTree a -> a -> BinaryTree a
add Empty x = Leaf x
add (Leaf y) x
  | x < y = Tree y (Leaf x) Empty
  | otherwise = Tree y Empty (Leaf x)
add (Tree y lc rc) x
  | x < y = Tree y (add lc x) rc
  | otherwise = Tree y lc (add rc x)

build :: Ord a => [a] -> BinaryTree a
build = buildAux empty
  where
    buildAux a [] = a
    buildAux a (x:xs) = buildAux (add a x) xs

-----------------------------PARTE 3--------------------------------------------

buildBalanced :: Ord a => [a] -> BinaryTree a
buildBalanced xs = buildBalanced' (sort xs) (length xs)
  where
    buildBalanced' [] _ = empty
    buildBalanced' [x] _ = leaf x
    buildBalanced' xs len = tree m (buildBalanced' lc lenLc) (buildBalanced' rc lenRc)
      where
        (lenLc, lenRc) = (len `div` 2, len - len `div` 2 - 1)
        (lc, m:rc) = splitAt (lenLc) xs

-----------------------------PARTE 4-------------------------------------------

preorder :: Ord a => BinaryTree a -> [a] 
preorder Empty = []
preorder (Leaf x) = [x]
preorder (Tree x lc rc) = [x] ++ preorder lc ++ preorder rc

postorder :: Ord a => BinaryTree a -> [a] 
postorder Empty = []
postorder (Leaf x) = [x]
postorder (Tree x lc rc) =  postorder lc ++ postorder rc ++ [x]

inorder :: Ord a => BinaryTree a -> [a] 
inorder Empty = []
inorder (Leaf x) = [x]
inorder (Tree x lc rc) =  inorder lc  ++ [x] ++ inorder rc 


balance :: Ord a => BinaryTree a -> BinaryTree a
balance a = buildBalanced (preorder a)

-----------------------------PARTE 5--------------------------------------------


between  :: Ord a => BinaryTree a -> a -> a -> [a]
between (Empty) _ _ = []
between (Leaf x) xmin xmax = if x >= xmin && x <= xmax then [x]
                             else []
between (Tree x lc rc) xmin xmax
  | x > xmax = between lc xmin xmax
  | x < xmin = between rc xmin xmax 
  | otherwise = between lc xmin xmax ++ [x] ++ between rc xmin xmax 
  
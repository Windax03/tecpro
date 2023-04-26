--------------------------------------------------------------------------------
-- File:   Tplot.hs
-- Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
-- Date:    abril 2023
-- Coms:    Fichero que almacena que hace cada operando
--------------------------------------------------------------------------------

module Tplot where

import Turtle

pos:: Turtle -> [Position]
pos (_,_,pos,_) = [pos]

tplot :: Turtle -> String -> [Position]
tplot turtle [] = pos turtle ++ []
tplot turtle (x:xs)
  | x == '>'  = pos turtle ++ tplot (moveTurtle turtle Forward) xs
  | x == '+'  = tplot (moveTurtle turtle TurnRight) xs
  | x == '-'  = tplot (moveTurtle turtle TurnLeft) xs
  | x == 'F'  = pos turtle ++ tplot (moveTurtle turtle Forward) xs
  | x == 'G'  = pos turtle ++ tplot (moveTurtle turtle Forward) xs
  | otherwise = tplot turtle xs
--------------------------------------------------------------------------------
-- File:   main.hs
-- Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
-- Date:    abril 2023
-- Coms:    Fichero que almacena el main que crea todas las figuras
--------------------------------------------------------------------------------

import SVG
import Tplot
import Lsystem


figura = tplot (1,90,(0,0),90) ">+>+>+>"
triangulo = tplot (1,120,(0,0),0) ">+>+>"
koch = tplot(1,60,(0,0),0) $ lsystem rulesKoch "F" 3
kochCuad = tplot(1,90,(0,0),0) $ lsystem rulesKochCuad "F" 3
snowflake = tplot(1,60,(0,0),0) $ lsystem rulesKochSnow "F++F++F" 3
anti_snowflake = tplot(1,60,(0,0),0) $ lsystem rulesKochAnti "F++F++F" 5
minkowski = tplot(1,90,(0,0),0) $ lsystem rulesMin "F+F+F+F" 2
sierpinsky = tplot(1,120,(0,0),180) $ lsystem rulesSier "F-G-G" 4
arrowhead = tplot(1,60,(0,0),0) $ lsystem rules "F" 6
hilbert = tplot(1,90,(0,0),180) $ lsystem rulesHiel "f" 4
gosper = tplot(1,60,(0,0),0) $ lsystem rulesGos "F" 3


main = do  
    savesvg "cuadrado" figura
    savesvg "triangulo" triangulo
    savesvg "Curva de Koch" koch
    savesvg "Curva de Koch cuadrada" kochCuad
    savesvg "Koch Snowflake" snowflake
    savesvg "Koch Anti-Snowflake" anti_snowflake
    savesvg "Isla de Minkowski" minkowski
    savesvg "Triangulo de Sierpinsky" sierpinsky
    savesvg "Sierpinsky Arrowhead" arrowhead
    savesvg "Curva de Hilbert" hilbert
    savesvg "Curva de Gosper" gosper




--------------------------------------------------------------------------------
-- File:   Lsystem.hs
-- Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
-- Date:    abril 2023
-- Coms:    Fichero que almacena las diferentes funciones que rescriben los operandos
--------------------------------------------------------------------------------

module Lsystem where

lsystem :: (Char -> String) -> String -> Int -> String
lsystem f s 0 = s 
lsystem f s n = concatMap f (lsystem f s (n-1)) 


--Ejemplo
rules :: Char -> String
rules 'F' = "G-F-G"
rules 'G' = "F+G+F"
rules '+' = "+"
rules '-' = "-"
rules _ = ""

--Curva de Koch
rulesKoch :: Char -> String
rulesKoch 'F' = "F+F--F+F"
rulesKoch '+' = "+"
rulesKoch '-' = "-"
rulesKoch _ = ""

--Curva de Koch cuadrada
rulesKochCuad :: Char -> String
rulesKochCuad 'F' = "F+F-F-F+F"
rulesKochCuad '+' = "+"
rulesKochCuad '-' = "-"
rulesKochCuad _ = ""

--Koch Snowflake
rulesKochSnow :: Char -> String
rulesKochSnow 'F' = "F-F++F-F"
rulesKochSnow '+' = "+"
rulesKochSnow '-' = "-"
rulesKochSnow _ = ""

--Koch Anti-Snowflake
rulesKochAnti :: Char -> String
rulesKochAnti 'F' = "F+F--F+F"
rulesKochAnti '+' = "+"
rulesKochAnti '-' = "-"
rulesKochAnti _ = ""

--Isla de Minkowski
rulesMin :: Char -> String
rulesMin 'F' = "F+F-F-FF+F+F-F"
rulesMin '+' = "+"
rulesMin '-' = "-"
rulesMin _ = ""

--Triángulo de Sierpinsky
rulesSier :: Char -> String
rulesSier 'F' = "F-G+F+G-F"
rulesSier 'G' = "GG"
rulesSier '+' = "+"
rulesSier '-' = "-"
rulesSier _ = ""

--Curva de Hilbert
rulesHiel :: Char -> String
rulesHiel 'f' = "-g>+f>f+>g-"
rulesHiel 'g' = "+f>-g>g->f+"
rulesHiel '>' = ">"
rulesHiel '+' = "+"
rulesHiel '-' = "-"
rulesHiel _ = ""

--Curva de Gosper
rulesGos :: Char -> String
rulesGos 'F' = "F-G--G+F++FF+G-"
rulesGos 'G' = "+F-GG--G-F++F+G"
rulesGos '+' = "+"
rulesGos '-' = "-"
rulesGos _ = ""
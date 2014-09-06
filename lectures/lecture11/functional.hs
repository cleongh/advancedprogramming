import Data.List

-- Haskell version
main = putStrLn $ intercalate "\n" $ map show $ map (+ 10) [1, 2, 3, 4, 5]

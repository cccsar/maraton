
gap :: (Integral a, Show a) => a -> a -> a -> String 
gap x y z
	| y - x == z - y = "AP " ++ show (z + y - x)
	| otherwise = "GP " ++ show (z * (y `div` x))

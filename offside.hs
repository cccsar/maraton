listMin :: (Ord a) => [a] -> a
listMin (x:xs)
	| length xs == 1 = min x y 
	| otherwise = min x (listMin xs)
	where 	y = head xs




nsteps :: (Integral a, Show a) => (a, a) -> String 
nsteps (x, y) 
	| x == y && even x = show (2 * x)
	| x == y && odd x = show (2 * x - 1)
	| x == y + 2 && even x = show (x + y)
	| x == y + 2 && odd y = show (x + y - 1)
	| otherwise = "No Number"


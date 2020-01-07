--p1

myLast :: [a] -> a 
myLast [] = error "empty list" 
myLast [a] = a 
myLast (x:xs) = myLast xs

--p2 reducir pattern matching

myButLast :: [a] -> a
myButLast [] = error "empty list" 
myButLast [x] = error "singleton"  
myButLast [x,y] = x
myButLast (x:xs) = myButLast xs

-- p3 mejorar

elementAt :: [a] -> Int -> a
elementAt [] _ = error "empty list"  
elementAt _ 0 = error "indexed from 1" 
elementAt (x:xs) e 
	| e == 1 = x 
	| otherwise = elementAt xs (e-1)

-- p4

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myLength' :: [a] -> Int
myLength' = foldr (\x acc -> acc + 1) 0

--p5
myReverse :: [a] -> [a] 
myReverse [] = [] 
myReverse [x] = x
myReverse (x:xs) = myReverse xs : [x]

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
myReverse (x:xs) = myReverse xs ++ [x] --this is ugly

--p6

isPalindrome :: (Eq a) => [a] -> Bool 
isPalindrome [] = error "empty list" 
isPalindrome x 
	| x == myReverse x = True
	| otherwise = False --this is also ugly

--p7 

data NestedList a = Elem a | List [NestedList a]

--foo:: NestedList a -> [a] 
--foo (Elem a) = [a] 
--foo (List a) = (foo $ head a) ++ (foo $ tail a )  

--flatten :: NestedList a -> [a]
--flatten (Elem x) = [x]
--flatten (List (x:xs)) = flatten x ++ flatten xs 

<<<<<<< HEAD
myMergesort :: (Ord a) => [a] -> [a]
myMergesort [] = []
myMergesort (x:xs) = (myMergesort left) ++ [x] ++ (myMergesort right)
	where 	left = filter (<x) xs
		right = filter (>x) xs	
=======

myQuicksort :: (Ord a) => [a] -> [a] 
myQuicksort (x:xs) = myQuicksort left ++ myQuicksort right 
	where 
		left = [a | a<-xs, a<=x] 
		right = [a | a<-xs, a>x]
--myQuicksort [x] = [x]
myQuicksort [] = [] 

>>>>>>> 4a91122204a0e5fad9dd7f4b7514f89dcdc8f892



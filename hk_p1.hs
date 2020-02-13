--p1
myLast :: [a] -> a
myLast [] = error "Empty list" 
myLast [x] = x
myLast (x:xs) = myLast xs

--p2
myButLast :: [a] -> a
myButLast [] = error "Empty list" 
myButLast [x] = x
myButLast [x,y] = x
myButLast (x:xs) = myButLast xs

--p3
elementAt :: (Ord a) => [a] -> Int -> a 
elementAt (x:xs) k 
	| k > 1 = elementAt xs (k-1)
	| otherwise = x 
elementAt [] _ = error "Not that much elements"  

--p4
myLenght :: [a] -> Int
myLenght (x:xs) = 1 + myLenght xs  
myLenght [] = 0 

myLenght' :: [a] -> Int
myLenght' = foldl (\acc x -> 1 + acc) 0 

--p5
myReverse :: (Eq a) => [a] -> [a] 
myReverse (x:xs) = myReverse xs ++ [x]
myReverse [] = [] 

myReverse' :: [a] -> [a] 
myReverse' xs = foldl (\acc x -> x:acc) [] xs


--p6

isEq :: (Eq a) =>  [a] -> [a] -> Bool 
isEq (x:xs) (y:ys)
	| x == y =  True && isEq xs ys
	| otherwise = False
isEq [] []  = True  
isEq [] x = False
isEq x [] = False 

isPalindrome :: (Eq a) => [a] -> Bool 
isPalindrome xs = isEq xs (reverse xs)

--p7 
data NestedList a = Elem a | List [NestedList a]

flatten :: [NestedList a] -> [a] 
flatten ((List x):xs) = flatten x ++ flatten xs 
flatten ((Elem x):xs) = [x] ++ flatten xs
flatten [] = [] 
-- SIIIIIIIIIIIIIIIIIIIIIi

--p8
compress :: (Eq a) => [a] -> [a] 
compress (x:p@(y:xs)) 
	| x /= y = x:compress p 
	| otherwise = compress p 
compress [x]  = [x] 
compress [] = [] 


--p9
pill :: [a] -> [[a]] 
pill [x] = [[x]] 
pill (x:xs) = [x]:pill xs
pill [] = [[]] 

bind :: [[a]] -> [[a]]
bind 
 

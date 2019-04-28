
n = int(input()) 
resp = []

for x in range(n): 
	arr = input().split()
	x = int( arr[0] ) 
	y = int( arr[1] ) 
	if x%2 == 1 and y%2 == 1 and ( x-y == 2 or x-y == 0): 
		resp.append( str(x+y-1) ) 
	elif x%2 == 0 and y%2 == 0 and ( x-y == 2 or x-y == 0) : 
		resp.append( str(x+y) )
	else: 	
		resp.append("No Number")

for i in resp: print(i)
		
		

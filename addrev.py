import math

n = int(input()) 
resp = []

def addrev(t:int)->int: 
	k = math.ceil( math.log10(t) ) 
	rv = 0
	u = t

	if t != 10**k : 
		k = k -1 
	else: 
		return t//10**k

	if k == 0: 
		return t 
	else: 
		while k != 0: 
			rv = rv + (u%10)*10**k 
			u = u//10
			k = k - 1
			
		return rv + u
			
for i in range(n):  
	arr = input().split()
	t1 = addrev( int(arr[0]) ) 
	t2 = addrev( int(arr[1]) ) 
	resp.append( addrev( t1 + t2 ) )
	
	
for i in resp: print(i) 
	

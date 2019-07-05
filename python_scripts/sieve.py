import math  

def erathostenes(n:int): 
	selection = [ int(x) for x in range(0,n+1) ]

	for i in range(2,math.floor(math.sqrt(n))): 

		if selection[i] != 0:
			for j in range(2*i, n+1, i):
				selection[j] = 0 
                
	selection[1] = 0 
	
	return selection

n = int(input())
a = erathostenes(n)

for c in range( len(a) ): 
	if (a[c] != 0):
		print(a[c])

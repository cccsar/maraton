import time
"""
def fibo(n:int)->int: 
	
	if n == 0: 
		return 1 
	elif n == 1: 	
		return 1 
	else: 	
		return fibo(n-1) + fibo(n-2) 
"""

def fibo1(n:int)->int: 
	tot, p = 0, 0
	for x in range(0, n+1): 	
		if x == 0: 
			tot = 1
		elif x == 1: 
			tot = 1
			p = 1 
		else: 	
			temp = tot
			tot = tot + p				
			p = temp

	return tot
		
def exponacci(n:int)->int: 
	if n == 0: 
		return 1
	else: 
		return 2**fibo1(n-1)
 

inp = int(input()) 
resp = []
times = []

for i in range(inp): 
	curr = int(input()) 

	beg = time.clock()	
	mezzo = exponacci(curr)%(10**9 + 7)
	end = time.clock()
	resp.append(mezzo)

	times.append(end-beg)

for i in resp: print(i)

tt = sum(x for x in times) 
print("total time: "+str(tt))


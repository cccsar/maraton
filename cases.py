import random

t = random.randint(1,10)
print( str(t) ) 

for i in range(t): 
	a = random.randint(1,1000000000)
	b = a + random.randint(1,10000)
	print( str(a)+" "+str(b) ) 



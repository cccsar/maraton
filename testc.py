import random 

n = random.randint(1,10) 

print(str(n)) 

for i in range(n): 
	print( str(random.randint(1,100)) + " " + str(random.randint(1,100)) ) 

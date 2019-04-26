import random 

n = random.randint(1,10000)
print(str(n)) 
for x in range(n): 
	el = random.randint(1,19)
	if el%3 == 0: 
		print("1/4")
	elif el%3 == 1: 
		print("1/2") 
	else: 
		print("3/4")

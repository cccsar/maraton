n = int(input())
pizza = [0,0,0]
 
for i in range(n): 
	fraction = input() 
	if fraction == "1/4":
		pizza[0]+=1
	elif fraction == "1/2": 
		pizza[1]+=1
	elif fraction == "3/4": 
		pizza[2]+=1

if pizza[1] >= 2: 
	if pizza[1]%2 == 0: 
		pizza[1] = pizza[1]//2
	else: 	
		pizza[1] = pizza[1]//2 + 1


if pizza[0] >= 1 and ( pizza[1] != 0 or pizza[2] != 0 ) : 
 
	if pizza[0] > 0: 
		if pizza[2] >= pizza[0]:
                        pizza[0] = 0 
		else: 
			pizza[0] -= pizza[2]

	if pizza[1]%2 == 1 and pizza[1] > 1: 
		if pizza[0] >= 2: 	
			pizza[0] -= 2
		else:
			pizza[0] -= 1
		
 
if pizza[0] > 0 and pizza[0] <=4: 
	pizza[0] = 1
else: 	
	if pizza[0]%4 == 0: 
		pizza[0] = pizza[0]//4
	else: 
		pizza[0] = pizza[0]//4 + 1

total = sum(x for x in pizza) + 1		
print(str(total)) 

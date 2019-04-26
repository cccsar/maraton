
n = int(input()) 

result = []
aux = []

def addrev(rev:int)->int: 
	b = True
	array = [] 
	while b == True: 
		if rev//10 != 0:
			array.append(rev%10)
		if rev//10 == 0 : 
			array.append(rev) 
			b = False
		rev=rev//10
	flush(array) 
	
	return sum( array[len(array)-1-i]*10**i for i in range(len(array)) ) 

def flush(k : list) : 
	while k[0] == 0: 
		k.pop(0) 
	while k[len(k)-1] == 0: 
		k.pop(len(k)-1) 

	
for x in range(n): 
	aux = input().split()
	t1 = addrev(int(aux[0]))
	t2 = addrev(int(aux[1])) 
	tot = t1 + t2
	
	naux = tot.split()
	result.append( str(tot) ) 	

for x in range(n): print(result[x]) 

		
	

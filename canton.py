a=[]
t = int(input()) 

for j in range(t): 
	a.append(int(input()))

for k in a:  
	num, den = 0, 0 
	i, p, e = 0, 0, 0 

	if k == 1: 
		print("TERM "+str(k)+" IS 1/1")	
	elif k ==2 : 
		print("TERM "+str(k)+" IS 1/2")	
	elif k == 3 : 
		print("TERM "+str(k)+" IS 2/1")
		#since the following formula works only for numbers k : k>3, we use base cases
	if k > 3: 

		while e < k :
			i+=1
			p=e #previous "e" value 
			e+=i

		if i%2 == 0: 
			num = k - p 
			den = i - (k - p - 1) 
		else: 
			num = i - (k - p - 1) 
			den = k - p
		print("TERM "+str(k)+" IS "+str(num)+"/"+str(den))



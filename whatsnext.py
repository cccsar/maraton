import time

beg = time.clock()
result = []
b = True

while b != False:
	k = input().split()
	k = [ int(x) for x in k ] 

	if k[0] == k[1] == k[2] == 0: 
		b = False	
	elif k[2] - k[1] == k[1] - k[0]: 
		nextT = k[2] + (k[1] - k[0])
		result.append("AP "+str(nextT) ) 
	elif k[1]//k[0] == k[2]//k[1]:
		nextT = k[2] * ( k[2]//k[1] )
		result.append("GP " + str(nextT) ) 

for x in result: print(x) 

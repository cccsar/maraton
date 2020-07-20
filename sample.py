import random

# Esto esta hecho para recordar como hacer control de flujo en python

tc = 1
k = 182 

print(tc)
print(k," ",k)
for i in range(1,k):
    for j in range(1,k): 
        if ( random.randint(1,50) % 2 == 0 ):
            print("1",end="") 
        else:
            print("0",end="") 
    print("") 

import random 

n = random.randint(0,100)
print( str(n) )

ex = n*n 

e = random.randint(0,ex - 1)
print( str(e) )

for c in range(e): 
    a = random.randint(0,n-1)
    b = random.randint(0,n-1)
    print( str(a) + " " + str(b), end="\n")



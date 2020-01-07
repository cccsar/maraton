from random import randint 

t = 2

print( str(t) )

for i in range(t): 
    
    n = randint(2,10); 
    print( str(n) ) 
    e = randint(1,n//2); 
    print( str(e) )
    for i in range(e):
        a = randint(1,e)
        b = randint(1,e)
        print( str(a) + " " + str(b))  

import math  

def erathostenes(n:int) -> [int]: 
    selection = [ int(x) for x in range(0,n+1) ]

    for i in range(2,math.floor(math.sqrt(n))): 
        if selection[i] != -1 : 
            for j in range(2*i, n+1, i):
                selection[j] = -1
                
    selection[0],selection[1] = -1, -1 
    primes = [ selection[x] for x in range(n+1) if selection[x] != -1 ] 

    return primes 




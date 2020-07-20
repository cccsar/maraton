import sys
import math 
import time

def erathostenes(n:int) -> [int]:
    selection = [ int(x) for x in range(0,n+1) ]

    for i in range(2,math.floor(math.sqrt(n))):
        if selection[i] != -1 :
            for j in range(2*i, n+1, i):
                selection[j] = -1

    selection[0],selection[1] = -1, -1
    primes = [ selection[x] for x in range(n+1) if selection[x] != -1 ]

    return primes

def serie(n:int): 
    k = n//2 
    return sum(10**(2*i) for i in range(k+1))

beg = time.clock()

n = int(sys.argv[1])
primes = erathostenes(n)
barray = [0 for x in range(len(primes))] 

for i in range(3, len(primes)): 
    b = True
    reference = primes[i]-2
    wnw = serie(reference)

    if wnw%primes[i] == 0:  
        reference -= 2
        wnw = serie(reference)

        while wnw > primes[i]: 

            if wnw%primes[i] == 0: 
                b = False
                break

            reference -= 2
            wnw = serie(reference)
    else: 
        b = False

    if b == True: 
        barray[i] = 1

count = sum(barray[i] for i in range(len(barray)))

end = time.clock()

print(count)
total = end-beg
print(total)




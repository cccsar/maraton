# This function asumes 1..n indexation
def printPath(p:[int])->[int] : 
	i, ps = 0, []
	while i != len(p): 
		if p[i] != -1: 
			r = [i+1] 
			k = p[i]
			t = i+1
			while k != t:
				r.append(k) 
				aux = k 
				k = p[k-1]
				t = aux 
			if len(r) != 1: 
				reverse(r)
			ps.append(r) 
		i = i + 1
	return ps

def reverse(arr:[int])->[int]: 
	i = 0
	while i!=len(arr)//2: 
		arr[i],arr[len(arr)-i-1] = arr[len(arr)-i-1],arr[i]
		i = i + 1
	return arr	

n = input().split()
n = [int(x) for x in n] 

k = printPath(n)
for i in k: print(i)


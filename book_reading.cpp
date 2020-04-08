#include <stdio.h>
#include <cmath>


const int MAXQ = 1000; 

long long resp[MAXQ+1];

long long foo(long long m, int upper) { 
	long long acum = 0; 

	for (int j=1; j<=upper; j++) acum += fmod(m*j, 10);  

	return acum; 	
}

int main() { 
	int Q; 
	long long N, M, k ; 
	scanf("%d",&Q); 

	for (int i=0; i<Q; i++) { 
		scanf("%lld %lld",&N, &M); 

		k = N/M; 
		if (N < M) 
			resp[i] = 0; 
		else 
			resp[i] = (k>10)? k/10*foo(M, 9) + foo(M, k%10) : foo(M, k); 
	}
	
	for (int j=0; j<Q; j++) printf("%lld\n",resp[j]); 
}

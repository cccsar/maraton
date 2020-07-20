#include <stdio.h> 

int main(){ 
	int t, n, m, a, b; 

	scanf("%d", &t); 

	while(t--)  {
		scanf("%d %d", &n, &m); 
		a = ( (n-2)%3 > 0)? 1: 0; 
		b = ( (m-2)%3 > 0)? 1: 0; 

		printf("%d\n", ((n-2)/3 + a) * ((m-2)/3 + b) );
	}
}

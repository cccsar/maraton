#include<stdio.h> 

int digitsum (int n) { 
	int accum = 0, e = n;

	while ( e > 10) { 
		accum += e%10; 
		e /= 10; 
	}	

	return accum + e%10 + e/10; 
}

int main() { 
	int a ; 

	scanf("%d", &a);

	int k = digitsum(a); 
	while ( k%4 ) {
		a += 1; 
		k = digitsum (a) ;
	}	

	printf ("%d\n",a ) ; 
}

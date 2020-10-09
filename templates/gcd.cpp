#include<stdio.h> 

using namespace std; 

int gcd(int a, int b ) { 

	if ( b==1 ) 
		return 1; 
	if ( b==0 ) 
		return a; 
	
	return gcd(b, a %b); 
}

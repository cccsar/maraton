#include<stdio.h> 
#include<iostream>

const int MAXX = 200000;

int fp[MAXX], x[MAXX]; 


using namespace std ; 


int foo(int index, int val) { 

	if ( index == 1 ) 
		return val ;
	else {
		if ( val == index ) 
			return 1;
		else if ( val > index ) 
			return val;
		return val + 1; 	
	}
}


int main() { 

	int n,m, i, j, acc; 

	scanf("%d %d", &n, &m) ;

	for (i=0; i<m; i++)  
		scanf("%d", &x[i]);

	acc = 0; 
	for (i=0; i<n; i ++ ) { 

		for(j=0; j<m-1 ; j++)  
			acc += abs( foo(i+1, x[j]) - foo(i+1, x[j+1]) ); 

		fp[i] = acc; 
		acc = 0 ;		
	}

	for (i=0; i<n; i++)  
		printf("%d ",fp[i]); 
	printf("\n"); 

	return 0 ; 
}

#include<iostream> 
#include<stdio.h> 
#include<string.h> 

using namespace std; 

const int MAXS = 200000; 

char a[MAXS+1], b[MAXS+1] ; 

bool eq(int p, int q, int r, int s) { 
	int size = (q-p+1)/2 ;

	if ( (q-p+1) % 2 == 0) { 
		bool fst = eq (p,p + size - 1, r, r + size - 1)  && eq( p + size , q, r + size, s) ; 
		if ( fst ) 
			return fst ;

		bool snd = eq (p, p + size - 1, r + size ,s) && eq ( p + size, q, r, r + size - 1) ;


		return snd;  
	}
	else { 
		bool chk = true ; 
		for(int i=0; i<=size ; i++) 
			if ( a[p+i] != b[r+i] ){
				chk = false; 
				break ;
			}
		return chk ; 
	}
}// check correctness

int main() { 
	int n;

	scanf("%s",a) ;
	scanf("%s",b) ; 	

	n = strlen(b); 

	printf("%s\n",eq(0,n-1,0, n-1)? "YES" : "NO"); 
}

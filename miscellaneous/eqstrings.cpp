#include<iostream> 
#include<stdio.h> 
#include<string.h> 

using namespace std; 

const int MAXS = 200000; 

char a[MAXS+1], b[MAXS+1] ; 


// check indexes
bool eq(int p, int q, int r, int s) { 
	if ( (q-p+1) % 2 == 0) { 
		bool fst = eq (p, p + (q-p+1)/2 - 1, r, r + (s-r+1)/2 - 1)  && eq( p + (q-p+1)/2 , q, r + (s-r+1)/2 , r) ; 
		if ( fst ) 
			return fst ;

		bool snd = eq (p, p + (q-p+1)/2 - 1, r + (s-r+1)/2 ,s) && eq ( p + (q-p+1)/2 , q, r, r + (s-r+1)/2 - 1) ;


		return snd;  
	}
	else { 
		bool chk = true ; 
		for(int i=0 ;i<=p + (q-p+1)/2; i++) 
			if ( a[p+i] != b[r+i] ){
				chk = false; 
				break ;
			}
		return chk ; 
	}

}

int main() { 
	int n, hlf;

	scanf("%s",a) ;
	scanf("%s",b) ; 	

	n = strlen(b); 
	hlf = n/2; 

	printf("%s\n",eq(0,hlf-1,hlf, n-1)? "YES" : "NO"); 
}

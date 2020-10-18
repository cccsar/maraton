#include<stdio.h> 
#include<iostream> 
#include<vector> 

using namespace std; 

const int MAXN = 17; 
const int MAXM = 100000; 

int a[(1<<(MAXN + 1))-1] ; 
int resp[MAXM] ; 

int upd(int ind, bool p) { 
	if ( ind == 0 ) 
		return a[0]; 

	int pp = (ind-1)/2;
	if ( ind % 2 == 0 ) 
		a[ pp ] = p ? a[ind-1] | a[ind] : a[ind-1] ^ a[ind]; 
	else 
		a[ pp ] = p ? a[ind] | a[ind+1] : a[ind] ^ a[ind+1] ;

	return upd( pp , p? false : true ); 
}

int main() { 
	int n,m, u,v ; 

	cin >> n >> m; 

	// agh
	for(int i= (1<<n) - 1 ;i< ( 1<<(n + 1) ) - 1; i++)   	// read leaves
		cin >> a[i] ; 

	for(int k=n; k>0; k--)  				// build heap
		for(int i=(1<<k)-1 ; i< (1<<(k+1))-1 ; i+= 2 )
			a[ (i-1) / 2 ] = ( (n-k)%2 == 0)? a[i] | a[i+1] : a[i] ^ a[i+1]; 


	int ind; 
	for(int i=0; i<m; i++) { 				// handle queries
		cin >> u >> v; 
		ind = (1<<n) -2 + u; 

		a[ ind ] = v ;
		resp[i] = upd(ind, true ) ; 
	}
	//

	int k = m ; 
	while ( k-- ) cout<<resp[m-k-1]<<endl ;
}

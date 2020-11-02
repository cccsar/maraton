#include<stdio.h> 
#include<iostream> 
#include<math.h> 

using namespace std; 

const int MAXN = 1000000; 

int st[4*MAXN] ; 
int arr[MAXN] ; 

int foo (int a, int b) { 
	return a + b; 
} 

int buildSt(int i, int p, int q) { 
	int r = p + (q-p)/2; 
	 
	if (p < q) 
		return st[i] = foo( buildSt( 2*(i+1)-1, p,r), buildSt(2*(i+1), r+1,q) ) ;

	return st[i] = arr[p] ;
}

int updSt(int i, int ind, int e, int p, int q) { 
	int r = p + (q-p)/2; 
	
	if (p <q) { 
		if ( ind <= r ) 
			return st[i] = foo( updSt( 2*(i+1)-1,ind,e, p, r), st[2*(i+1)] ); 
		return st[i] = foo( st[2*(i+1)-1], updSt(2*(i+1), ind, e, r+1, q) ); 
	}

	return st[i] = arr[q] = e; 
}

int querySt(int curr, int i, int j, int p , int q ){ 

	if (p<q) 
		return 0 ; 

	if (i==p && j==q)
		return st[curr]; 

 	int sz = q-p; 

	return foo ( querySt( 2*(i+1)-1, i, min(j,p+sz/2), p, p+sz/2), querySt( 2*(i+1), max(i, p+sz/2+1), j, p+sz/2+1, q) ); 

} // check this out

int main(){ 
	int n; 

	cin >> n; 

	for(int i=0 ;i<n; i++)  
		cin >> arr[i]; 

	buildSt(0, 0, n-1) ; 

	for(int i=0 ;i<4*n; i++) cout<<st[i]<<" ";
	cout<<endl; 

	updSt(0, 4, 5,0,n-1); 
	
	for(int i=0 ;i<4*n; i++) cout<<st[i]<<" ";
	cout<<endl; 
}

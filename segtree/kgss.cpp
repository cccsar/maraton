#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<math.h> 

using namespace std; 

const int MAXN = 100000;
const int MAXST = 1<<(ilogb(MAXN) + 1); 

int arr[MAXN] ; 
int st[MAXST] ; 
int resp[MAXN]; 

int buildSt(int ind, int p, int q){
	int sz = q - p ; 

	if ( sz > 0 )  
		return st[ind] = max(buildSt( 2*(ind+1)-1, p, p + sz/2) ,buildSt( 2*(ind+1), p + sz/2 + 1,q )); 

	return st[ind] = arr[p]; 
} 

int updSt(int curr, int ind, int el, int p, int q) {
	int sz = q-p; 

	if ( sz > 0) {  
		if ( ind <= p + sz/2 ) // left son update
			return st[curr] = max(updSt( 2*(curr+1)-1,ind,el, p, p+sz/2) , st[ 2*(ind+1) ]); 
		return st[curr] = max(st[ 2*(curr+1)-1 ] , updSt( 2*(curr+1), ind, el, p + sz/2 +1, q)); 
	}	

	return st[curr] = arr[ind] = el ;
}

int segLookup(int curr, int p, int q, int i, int j ) { 
	if ( i > j ) 
		return -1; 

	if ( i == p && j == q ) 
		return st[curr]; 

	int sz = q-p ; 
	return max ( segLookup( 2*(curr+1) -1, p, p +sz/2, i, min (j, p + sz/2) ) ,
		segLookup( 2*(curr+1), p +sz/2 + 1, q, max( i  , p + sz/2+1) , j) ) ; 
}	


int main() { 
	int n,m; 

	cin >> n; 

	int hsz = ilogb(n) + 1; 

	for(int i=0 ;i<n; i++) cin>> arr[i]; 

	buildSt(0, 0, n-1) ; 

//	for(int i=0 ;i<(1<<(hsz+1)) + 1; i++) cout<<st[i]<<" "; 
//	cout<<endl; 

	cin >> m ; 
	char let; 
	int u, v, a, b; 
	for (int i=0 ;i<m; i++) { 
		cin >>let>>u>>v; 
		if ( let == 'Q' ){
		}
		else  
			resp[i] = updSt(0, u-1, v-1, 0, n-1) ; 
	}
}















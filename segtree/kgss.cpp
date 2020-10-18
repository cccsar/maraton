#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<math.h> 

using namespace std; 

const int MAXN = 100000;
const int MAXST = 4*MAXN;  

int arr[MAXN] ; 
pair<int, int> st[MAXST] ; 
vector<int> resp; 

pair<int, int> foo ( pair<int, int> yo, pair<int, int> lo ) {
	if ( yo.first >= lo.first )  
		return { yo.first, max( yo.second, max(lo.first, lo.second) ) } ;

	return { lo.first, max( lo.second, max ( yo.first, yo.second ) ) } ; 
}

pair<int, int> buildSt(int ind, int p, int q){
	int sz = q - p ; 

	if ( sz > 0 )  
		return st[ind] = foo( buildSt( 2*(ind+1)-1, p, p+sz/2), buildSt(2*(ind+1), p+sz/2+1, q) ); 

	return st[ind] = { arr[p], -1} ;  
} 

pair<int, int> updSt(int curr, int ind, int el, int p, int q) {
	int sz = q-p; 

	if ( sz > 0) {  
		if ( ind <= p + sz/2 ) // left son update
			return st[curr] = foo ( updSt( 2*(curr+1)-1,ind,el, p, p+sz/2) , st[ 2*(curr+1) ]); 
		return st[curr] = foo( st[ 2*(curr+1)-1 ] , updSt( 2*(curr+1), ind, el, p + sz/2 +1, q)); 
	}	

	st[curr].first = el ;
	return st[curr];  
}

pair<int, int> segLookup(int curr, int p, int q, int i, int j ) { 
	if ( i > j ) 
		return { -1, -1 } ; 

	if ( i == p && j == q ) 
		return st[curr]; 

	int sz = q-p ; 
	return foo( segLookup( 2*(curr+1) -1, p, p +sz/2, i, min (j, p + sz/2) ) ,
		segLookup( 2*(curr+1), p +sz/2 + 1, q, max( i  , p + sz/2+1) , j) ) ; 
}	


int main() { 
	int n,m; 

	cin >> n; 

//	int hsz = ilogb(n) + 1; 

	for(int i=0 ;i<n; i++) cin>> arr[i]; 

	buildSt(0, 0, n-1) ; 

//	for(int i=0 ;i<(1<<(hsz+1)) + 1; i++) cout<<st[i].first<<" "<<st[i].second<<" "; 
//	cout<<endl; 

	cin >> m ; 

	char let; 
	int u, v; 
	pair<int, int> help; 

	for (int i=0 ;i<m; i++) { 
		cin >>let>>u>>v; 
		if ( let == 'Q' ){
			help = segLookup(0,0,n-1,u-1,v-1); 
			resp.push_back( help.first + help.second ); 
		}
		else  
			updSt(0, u-1, v, 0, n-1) ; 
	}

	for(int el : resp ) cout<<el<<endl; 
}















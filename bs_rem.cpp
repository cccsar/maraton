#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<set> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 

using namespace std; 

#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",&s)

typedef vector< int > vi; 
typedef vector< pair<int, int> >  vii; 
typedef vector< int, pair<int, int> >viii; 
typedef pair <int, int> pi; 
typedef pair <int, pair<int, int> > pii; 
typedef vector< vi > adl; 
typedef vector< vii > wadl; 
	
bool bs(int arr[], int e, const int p, const int q) { 
	int k =  q - (q-p)/2 +1 ; 

	if ( arr[k] > e ) {
		if ( k == q ) 
			return false; 
		bs(arr, e, p, k); 
	}	
	else if ( arr[k] < e ){ 
		if ( k == p ) 
			return false; 
		bs(arr, e, k, q ); 
	}
	else 
		return true; 
}

int main() 
{
	int cost[10], i_; 

	for(i_=1; i_<10 ; i_+=2) {
		cost[i_] = i_+1; 
	}



	cout<<bs(cost, 2, 0, 9)<<endl; 
	return 0; 
}

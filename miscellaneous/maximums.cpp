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

const int MAXINT = 2147483647;

const int MAXS = 200000; 

int as[MAXS], bs[MAXS], xs[MAXS]; 

void foo(int n ) { 
	int i_; 

	as[0] = bs[0] ; 
	xs[0] = 0; 
	
	for(i_=1; i_<n ;i_++) { 
		xs[i_] = max( xs[i_-1], as[i_-1] ) ; 
		as[i_] = bs[i_] + xs[i_] ; 	
	}	
		
}
int main() 
{
	int n, i_; 

	ri(n); 
	for(i_=0; i_<n ;i_++)  
		ri(bs[i_]);

	foo(n) ;

	for(i_=0; i_<n ;i_++)  
		cout<<as[i_]<<" "; 
	cout<<endl; 

	return 0; 
}

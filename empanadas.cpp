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

const int MAXN = 1000;
int a[MAXN], b[MAXN]; 
int dp[2][MAXN] ;

int empanada(int n, const bool test) { //true is for a and false is for b
	if ( n == 0 ) {
		if (test) {
			if (dp[0][0] == -1) 
				dp[0][0] = a[0] ; 
			return dp[0][0]; 	
		}
		else { 
			if (dp[1][0] == -1) 
				dp[1][0] = b[0] ; 
			return dp[1][0] ;
		}
	
	}
	else if ( n == 1 ) {
		if (test) { 
			if (dp[0][1] == -1) 
				dp[0][1] = a[1] + b[0] ; 
			return dp[0][1]; 
		}
		else { 
			if (dp[1][1] == -1) 
				dp[1][1] = b[1] + a[0]; 
			return dp[1][1]; 
		}
	}
	else { 
		if (test) { 
			if (dp[0][n] == -1)  
				dp[0][n] = max( a[n] + empanada(n-1, false), a[n] + empanada(n-2,false) );

			return dp[0][n]; 
		}
		else { 
			if (dp[1][n] == -1)
				dp[1][n] = max( b[n] + empanada(n-1, true), b[n] + empanada(n-2, true) ) ;

			return dp[1][n]; 
		}

		
	}
}

int main() 
{
	int n, i_ , carne, queso;

	for(i_=0; i_<MAXN ;i_++)  
		dp[0][i_] = dp[1][i_] = -1 ;

	ri(n); 
	for(i_=0; i_<n ;i_++)  
		ri(a[i_]); 		
	for(i_=0; i_<n ;i_++)  
		ri(b[i_]); 		

	carne = empanada(n-1, true); 
	queso = empanada(n-1, false); 

	cout<<max( carne, queso )<<endl;

	return 0; 
}

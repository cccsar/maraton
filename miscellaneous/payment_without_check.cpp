
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


const int MAXT = 10000; 

bool resp[MAXT]; 

int main() 
{
	int n, a, b, s, q, c, quot, i_, diff; 

	ri(q);
	c = q+1 ;

	while ( c-- ){ 
		rii(a, b); 
		rii(n, s); 

		if ( a*n + b < s) 
			resp[q-c] = false; 
		else if ( a*n + b == s )
			resp[q-c] = true; 
		else { 
			diff = n*a + b - s;
			quot = diff/n; 
			if ( quot > a )  
				resp[q-c] = true; 
			else { 
				if ( diff - quot*n <= b) 
					resp[q-c] = true; 
				else
					resp[q-c] = false; 
			}
		}
	}

	for(i_=0; i_<q ;i_++) { 
		(resp[i_])? cout<<"YES\n" : cout<<"NO\n"; 
	}	

	return 0; 
}

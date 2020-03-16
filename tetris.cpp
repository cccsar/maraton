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

const int MAXS = 100;

int main() 
{
	int t ,n, i_, c; 
	int tet[MAXS], even, odd; 
	bool resp[MAXS];

	ri(t); 
	c = t+1; 
	while(c--) {
		even = odd = false;

		ri(n); 
		for(i_=0; i_<n ; i_++) {
			ri(tet[i_]);
			(tet[i_] % 2 == 0)? even = true: odd = true; 
		}	
		
		resp[t-c] = even & odd; 
	}

	for(i_=0; i_<t ; i_++) 
		(resp[i_])? cout<<"NO"<<endl : cout<<"YES"<<endl ; 

	return 0; 
}

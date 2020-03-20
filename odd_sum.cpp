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

const int MAXG = 2000; 

int terms[MAXG]; 
bool resp[MAXG];

int main() 
{
	int t, n, c, even, odd, i_; 

	ri(t); 

	c = t + 1; 

	while(c--){ 
		ri(n); 

		even = odd = 0; 

		for(i_=0; i_<n ; i_++) {
			ri(terms[i_]); 

			if ( terms[i_] % 2 == 0)  
				even += 1; 
			else 
				odd += 1; 
		}	

		if ( even > 0 && odd > 0 ) 
			resp[t-c] = true; 
		else if ( even > 0 && odd == 0 ) 
			resp[t-c] = false; 
		else 
			resp[t-c] = ( odd % 2 == 0 )? false : true; 
	}

	for (i_=0; i_<t; i_++) 
		(resp[i_])? cout<<"YES\n" : cout<<"NO\n"; 

	return 0; 
}

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

const int MAXX =200; 

bool resp[MAXX]; 
int arr[MAXX]; 

int main() 
{
	int q, n, i_, c, j_; 

	ri(q); 

	for(j_=0; j_<q; j_++) { 
		ri(n); 

		for(i_=0; i_<n ;i_++)  
			scanf("%d",&arr[i_]); 
	
		if ( n != 1 ) { 	
			sort(arr, arr + n); 
		
			for(i_=0; i_<n-1 ;i_++) { 
				if ( arr[i_] + 1 == arr[i_+1] ) {
					resp[j_] = true; 		
					break; 
				}
			}
		}
	
	}

	for(i_=0; i_<q ;i_++)  
		(resp[i_])? cout<<"2\n" : cout<<"1\n"; 

	return 0; 
}

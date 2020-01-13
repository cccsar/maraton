#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<set> 
#include<string> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 
#include<string.h>


#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",s)
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 

#define UB 5 
#define MAXSS 10
	
using namespace std; 

int parents[100000];
int ranks[100000]; 
int resp[10]; 

int myFind(int e) {
	int dummie ; 
	
	dummie = e ;	
	while( parents[dummie] != -1 )  { 
		dummie = parents[dummie]; 
	}

	if ( dummie != e ) 
		parent[ e ] = dummie; 

	return dummie; 
	
	
}


void myUnion(int u, int v) {
	int x, y; 

	x = myFind(u); 
	y = myFind(v); 
	if ( x != y ) {

		if ( ranks[x] >= ranks[y])  {
			parents[y] = x; 	
			if ( ranks[x] == ranks[y]) 
				ranks[x] ++; 
		}
		else 
			parents[x] = y ; 

	}
}

int main() 
{
}

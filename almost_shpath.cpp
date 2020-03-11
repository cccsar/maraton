#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<set> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<unordered_set> 

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
const int MAXS = 500;
const int MAXT = 100;

int cost[2][MAXS] ; 
int resp[MAXT] ;


void reverse(vii graph[], vii invgraph[], int size ) { 
	int i_ ;

	for (i_=0 ; i_<size ; i_++) { 
		for(pi k : graph[i_] ) 
			invgraph[ k.second ].push_back( { k.first, i_ } );
	}

}



void myDijkstra(vii graph[], int cost[][MAXS], int source, int i) { 
	priority_queue< pii, vector<pii> , greater<pii> > pq; 
	pi dummie; 

	pq.push( { 0, source } ); 
	cost[i][source] = 0 ; 

	while ( !pq.empty() ) { 
		dummie = pq.top(); 
		pq.pop(); 

		for(pi suc : graph[ dummie.second ] ) { 
			if ( cost[ succ.second ] > cost[ k.second ] + k.first ) { 

			}
		}		
	}
}
int main() 
{
	int n, m, s, d, u, v, p, i_; 
	vii *digraph ,*invgraph;

	digraph = new vii[MAXS]; 
	invgraph = new vii[MAXS]; 

	while ( true ) { 

		rii(n, m); 	
		if ( n == 0 ) 
			break; 

		rii(s, d); 	
		for (i_=0 ; i_<m ; i_++) { 
			riii(u, v, p); 
			digraph[u].push_back( {p, v} ); 
		}	

		
	}
	return 0; 
}

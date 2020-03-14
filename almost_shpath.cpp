#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<set> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>

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


bool excluded[MAXS][MAXS];
int resp[MAXT] ;


void reverse(vii graph[], vii invgraph[], int size ) { 
	int i_ ;

	for (i_=0 ; i_<size ; i_++) { 
		for(pi k : graph[i_] ) 
			invgraph[ k.second ].push_back( { k.first, i_ } );
	}

}



void myDijkstra(vii graph[], int cost[MAXS], int source, int size) { 
	priority_queue< pi, vector<pi> , greater<pi> > pq; 
	int i_, itt; 
	pi dum, itt; 

	pq.push( { 0, source } ); 
	cost[source] = 0 ; 

	while ( !pq.empty() ) { 
		dum = pq.top(); 
		pq.pop(); 

		//for(pi succ : graph[ dum.second ] ) { 
		for(i_=0; i_<graph[dum.second].size() ; i_++) {
			itt = graph[dum.second][i_];

			//if ( cost[ succ.second ] > cost[ dum.second ] + succ.first 

			if ( cost[ itt.second ] > cost[ dum.second ] + itt.first 
					&& !excluded[ dum.second ][ itt.second ] ) { 

				cost[ itt.second ] = cost[ dum.second ] + itt.first
				//cost[ succ.second ] = cost[ dum.second ] + succ.first ; 
				pq.push( succ ) ; 
			}
		}		
	}
}


int main() 
{
	int n, m, s, d, u, v, p, i_, count; 
	int cost_s[MAXS], cost_d[MAXS];
	pi itt; 
	vii *digraph ,*invgraph, *reset;

	digraph = new vii[MAXS]; 
	invgraph = new vii[MAXS]; 
	reset = new vii; 

	for(i_=0; i_<MAXS ; i_++)
		cost_s[i_] = cost_d[i_] = MAXINT; 	

	count = 0 ;

	while ( true ) { 

		rii(n, m); 	
		if ( n == 0 ) 
			break; 

		rii(s, d); 	

		for (i_=0 ; i_<m ; i_++) { 
			riii(u, v, p); 
			digraph[u].push_back( {p, v} ); 
		}	

		reverse(digraph, invgraph, n); 

		//compute shortest path from both source and destination
		myDijkstra(digraph, cost_s, s); 
		myDijkstra(invgraph, cost_d, d); 


		//using computed path, find all edges belonging to a shortest path and add
		//them to the exclusion matrix
		for(i_=0; i_<n ; i_++) {
			
			//for(pi edge: digraph[i_] ) { 
			for(j_=0; j_<digraph[i_].size() ; j_++) {
				itt = digraph[i_][j_];
				//if ( cost_s[i_] + edge.first + cost_d[ edge.second ] == cost_s[ d ] )  {
				if ( cost_s[i_] + itt.first + cost_d[ itt.second ] == cost_[ d] ) { 
					//excluded[i_][ edge.second ] = true; 
					excluded[i_][ itt.second ] = true; 
					//reset->push_back( {i_, edge.second } ) ; 
					reset->push_back( {i_, itt.second } ); 
				}	
			}
			cost_s[i_] = MAXINT; //reset cost from source while excluding edges
		}	

		//recompute dijkstra, this time only from source and return shortest path found
		myDijkstra( digraph, cost_s, s); 

		resp[ count ] = ( cost_s[ d ] != MAXINT )? cost_s[d] : -1 ; 
		count += 1; 	

		//reset
		for(i_=0; i_<n ; i_++) {
			cost_s[i_] = cost_d[i_] = MAXINT; 	
			digraph[i_].clear(); 
			invgraph[i_].clear(); 
		}	

		//for(pi vis : *reset) 		//this should be at least n^2.. hope not
		for(i_=0; i_<reset.size() ; i_++) {
			//excluded[vis.first][vis.second] = false; 
			excluded[ reset[i_].first ][ reset[i_].second ] = false; 
		}
		reset->clear(); 
	}

	for(i_ = 0; i_<count; i_++) 
		cout<<resp[i_]<<endl; 

	return 0; 
}

#include <stdio.h> 
#include <iostream> 
#include <queue> 
#include <vector> 

#define MAXS 501 
#define MAXT 10000

using namespace std ;

typedef pair<short, short> pi ; 
typedef vector< pi > vii ; 
typedef priority_queue< pi, vector<pi>, greater<pi> > minQ; 

vii *graph = new vii [MAXS] , * revGraph = new vii [MAXS] ; 
short cost[MAXS], parent[MAXS], rCost[MAXS], rParent[MAXS] ; 
int resp[MAXT] ;

void dijkstra(int source, vii graph[], short cost[MAXS], short parent[MAXS]) { 
	minQ myQ; 
	pi dum, help, jj; 
	cost[source] = 0 ; 
	parent[source] = source; 

	jj.first = 0; jj.second = source; 
	myQ.push( jj ) ; 

	while ( !myQ.empty() ) { 
		dum = myQ.top() ;
		myQ.pop() ;

		if ( dum.first > cost[dum.second]) continue; 

		for(unsigned i=0; i<graph[dum.second].size() ; i++)  {
			help = graph[dum.second][i] ; 
			if ( help.first != -1 &&  cost[ dum.second ] + help.first < cost[ help.second ] ) { 
			 	cost[help.second] = cost[ dum.second ] + help.first ;
				parent[help.second ] = dum.second; 

				jj.first = cost[help.second] ; jj.second = help.second ; 
				myQ.push( jj ) ; 
			}		
		}
	}
}

void delEdge (short u, short v ) { 
	pi help ; 
	// representative elimination (-1 weight)
	
	for(unsigned i=0; i<graph[u].size() ; i++ )
		if ( graph[u][i].second == v ) { 
			help.first = -1;  help.second = graph[u][i].second ; 
			graph[u][i] = help  ; 
			break ;
		}

	for(unsigned i=0; i<graph[v].size() ; i++ ) // other edge ### 
		if ( graph[v][i].second == u ) { 
			help.first = -1;  help.second = graph[v][i].second ; 
			graph[v][i] = help  ; 
			break ;
		}
			
			
}

void delPath (int pivot) { 

	int dum = pivot ; 
	while( dum != parent[dum] )  { 
		delEdge( parent[dum], dum ) ; 
		dum = parent[dum] ; 
	}

	dum = pivot; 
	while ( dum != rParent[dum] ) { 
		delEdge( dum, rParent[dum] ) ; 
		dum = rParent[dum] ; 
	}
}

int main() { 
	short n, m, s, d , cnt = 0; 

	while ( scanf("%hd %hd",&n, &m ) && n != 0 && m != 0 ) {
       		scanf("%hd %hd",  &s, &d) ; 

		for (short i=0 ;i<n ;i++) { cost[i] = rCost[i] = MAXS; parent[i] = rParent[i] = -1 ; } //init

		short u,v, w; 
		for (short i=0; i<m; i++) { 
			pi help; 
			scanf("%hd %hd %hd",&u, &v, &w) ; 
			help.first = w; help.second = v; 
			graph[u].push_back ( help ) ; 

			help.second = u; 
			revGraph[v].push_back (help); 
			
		}

		// algorithm goes here

		dijkstra(s, graph, cost, parent) ; 
		dijkstra(d, revGraph, rCost, rParent) ; 


		for(short i=0; i<n; i++)  
			if( cost[i] + rCost[i] == cost[d] ) 
				delPath( i ) ; 
			

		for(short i=0; i<n; i++) { cost[i] = MAXS ; parent[i] = -1; } 

		dijkstra(s, graph, cost, parent) ;
		
		//

		resp[cnt] = (cost[d] == -1 || cost[d] == MAXS)? -1 : cost[d] ; 

		for (int i=0 ;i<n ; i++) { graph[i].clear() ; revGraph[i].clear() ; } //cleanup 
		cnt+=1 ;
	}

	for(short i=0; i<cnt ; i++) printf("%d\n",resp[i]); 

}

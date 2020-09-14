#include <stdio.h> 
#include <iostream> 
#include <queue> 
#include <vector> 
#include <utility> 

#define MAXS 501

using namespace std ;

typedef pair<int, int> pi ; 
typedef vector< pi > vii ; 
typedef priority_queue< pi, vector<pi>, greater<pi> > minQ; 

vii *graph = new vii [MAXS] , * revGraph = new vii [MAXS] ; 
int cost[MAXS], parent[MAXS], rCost[MAXS], rParent[MAXS] ; 
int resp[MAXS] ;
minQ myQ; 

void dijkstra(int source, vii graph[], int cost[], int parent[]) { 
	pi dum, help, jj; 
	cost[source] = 0 ; 
	parent[source] = source; 

	jj.first = 0; jj.second = source; 
	myQ.push( jj ) ; 

	while ( !myQ.empty() ) { 
		dum = myQ.top() ;
		myQ.pop() ;

		for(unsigned i=0; i<graph[dum.second].size() ; i++)  {
			help = graph[dum.second][i] ; 
			if ( help.second != -1 &&  cost[ dum.second ] + help.first < cost[ help.second ] ) { 
			 	cost[help.second] = cost[ dum.second ] + help.first ;
				parent[help.second ] = dum.second; 

				jj.first = cost[help.second] ; jj.second = help.second ; 
				myQ.push( jj ) ; 
			}		
		}
	}
}

void reverse(int size) { 
	int k = size;
	pi help; 

	while ( k -- )  
		for (unsigned i=0; i<graph[k].size(); i++) {
			help.first = graph[k][i].first; help.second = k; 
			revGraph[ graph[k][i].second ].push_back (help); 
		}
}

void delEdge (int u, int v ) { 
	pi help ; 
	
	for(unsigned i=0; i<graph[u].size() ; i++ )
		if ( graph[u][i].second == v ) { 
			help.first = graph[u][i].first; help.second = -1 ; // representative elimination
			graph[u][i] = help  ; 
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
	int n, m, s, d , cnt = 0; 
	pi help; 

	while ( scanf("%d %d",&n, &m ) && n != 0 && m != 0 ) {
       		scanf("%d %d",  &s, &d) ; 

		for (int i=0 ;i<n ;i++) { cost[i] = rCost[i] = MAXS; parent[i] = rParent[i] = -1 ; } //init

		int u,v, w; 
		for (int i=0; i<m; i++) { 
			scanf("%d %d %d",&u, &v, &w) ; 
			help.first = w; help.second = v; 
			graph[u].push_back ( help ) ; 
		}

		// algorithm goes here

		reverse(n) ; 
		dijkstra(s, graph, cost, parent) ; 
		dijkstra(d, revGraph, rCost, rParent) ; 


		for(int i=0; i<n; i++)  
			if( cost[i] + rCost[i] == cost[d] ) 
				delPath( i ) ; 
			

		for(int i=0; i<n; i++) { cost[i] = MAXS ; parent[i] = -1; } 
		dijkstra(s, graph, cost, parent) ;
		
		resp[cnt] = (cost[d] == -1 || cost[d] == MAXS)? -1 : cost[d] ; 

		//
		
		for (int i=0 ;i<n ; i++) { graph[i].clear() ; revGraph[i].clear() ; } //cleanup 
		cnt+=1 ;
	}

	for(int i=0; i<cnt ; i++) printf("%d\n",resp[i]); 

}

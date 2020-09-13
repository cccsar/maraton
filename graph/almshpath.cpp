#include <stdio.h> 
#include <iostream> 
#include <queue> 
#include <vector> 
#include <utility> 

#define MAXS 500

using namespace std ;

typedef pair<int, int> pi ; 
typedef vector< pi > vii ; 
typedef priority_queue< pi, vector<pi>, greater<pi> > minQ; 

vii *graph = new vii [MAXS] , * revGraph = new vii [MAXS] ; 
int cost[MAXS], parent[MAXS], rCost[MAXS], rParent[MAXS] ; 
int resp[MAXS] ;
minQ myQ; 

void dijkstra(int source, vii graph[], int cost[], int parent[]) { 
	pi dum; 
	cost[source] = 0 ; 
	parent[source] = source; 
	myQ.push( {0, source} ) ; 

	while ( !myQ.empty() ) { 
		dum = myQ.top() ;
		myQ.pop() ;

		for ( pi v : graph[ dum.second ] )  
			//consider "deleted" edges
			if ( v.second != -1 &&  cost[ dum.second ] + v.first < cost[ v.second ] ) { 
			 	cost[v.second] = cost[ dum.second ] + v.first ;
				parent[v.second ] = dum.second; 

				myQ.push( { cost[v.second], v.second } ) ; 
			}		
	}
}

void reverse(int size) { 
	int k = size;

	while ( k -- )  
		for ( pi v : graph[k] ) 
			revGraph[ v.second ].push_back ({ v.first, k } ); 
}

void delEdge (int u, int v ) { 
	
	for(unsigned i=0; i<graph[u].size() ; i++ )
		if ( graph[u][i].second == v ) 
			graph[u][i] = { graph[u][i].first, - 1} ; // representative elimination
			
}

void delPath (int pivot) { 
	//use parent and rParent	

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

	while ( scanf("%d %d",&n, &m ) && n != 0 && m != 0 ) {
       		scanf("%d %d",  &s, &d) ; 

		for (int i=0 ;i<n ;i++) { cost[i] = rCost[i] = MAXS; parent[i] = rParent[i] = -1 ; } //init

		int u,v, w; 
		for (int i=0; i<m; i++) { 
			scanf("%d %d %d",&u, &v, &w) ; 
			graph[u].push_back ({ w, v} ) ; 
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

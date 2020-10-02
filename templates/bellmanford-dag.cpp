#include<stdio.h> 
#include<vector> 
#include<queue> 
#include<utility> 

#define MAXS 1000000
#define MAXINT 0x7fffffff // initial costs

using namespace std; 

typedef pair<int, int> pi ;
typedef vector<pi> wgraph; 

wgraph *graph = new wgraph [MAXS]; 

int cost[MAXS], deg[MAXS]; 

void bellman(int source ) { //assumes single source, no cycle and connected.. detects cycles?
	queue<int> ord; 
	int el ;
	bool chg ; 

	ord.push(source); 
	cost[source] = 0; 

	while ( !ord.empty() ) { 
		el = ord.front(); 
		ord.pop(); 

		chg = false; 

		for(pi ady : graph[el] ) { 
			deg[ady.second] -= 1; 
			if ( deg[ady.second] == 0) {  // if adyacent goes indeg==0, then is next to be checked
				ord.push( ady.second) ;
				chg = true; 
			}
			
			if ( cost[el] + ady.first < cost[ady.second] )  
				cost[ady.second] = cost[el] + ady.first ; 
		}	

	}
}

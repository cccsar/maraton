#include<stdio.h> 
#include<vector> 
#include<utility> 

#define MAXS 10000
#define MAXINT 0x7fffffff

using namespace std; 

typedef pair<int, int> pi; 
typedef vector<pi> wgraph; 

wgraph *graph = new wgraph[MAXS]; 

int cost[MAXS], parent[MAXS]; 

bool bellmanford(int size, int source) { 
	bool chg = true; 
	int cnt = 0 ;

	cost[source] = 0; parent[source] = source; 

	while ( chg && cnt != size) {

		chg = false; 
		
		for(int i=0 ;i<size; i++) 
			for(pi ady : graph[i] )
				if ( cost[i] + ady.first < cost[ady.second])  {
					cost[ady.second] = cost[i] + ady.first; 
					parent[ady.second] = i; 

					chg = true; 
				}

		cnt +=1; 
	}


	for(int i=0 ;i<size; i++) 
		for(pi ady : graph[i] )
			if ( cost[i] + ady.first < cost[ady.second]) 
				return true; 

	return false;
}

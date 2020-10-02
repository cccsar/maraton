#include<stdio.h> 
#include<vector> 
#include<utility> 
#include<queue> 
#include<iostream> 

#define MAXS 1000000
#define MAXINT 0x7fffffff

using namespace std; 

typedef pair<int, int> pi; 
typedef vector<pi> wgraph  ; 

wgraph * graph = new wgraph[MAXS]; 
priority_queue<pi> myQ; 

int cost[MAXS], parent[MAXS]; 

void dijkstra(int source) { 
	pi eg ; 
	cost[source] = 0; 
	parent[source] = source; 

	myQ.push({ 0, source } ); 

	while (!myQ.empty()) { 
		eg = myQ.top() ;
		myQ.pop(); 

		if ( -eg.first > cost[eg.second] ) continue ; // erasing this line will enable path reopening

		for(pi ady : graph[eg.second] )  
			if ( cost[eg.second] + ady.first < cost[ady.second] ) { 
				cost[ady.second] = cost[eg.second] + ady.first; 
				parent[ady.second] = eg.second; 

				myQ.push( {-cost[ady.second], ady.second} ) ;// maxPQ with negative costs
			}
	}
}

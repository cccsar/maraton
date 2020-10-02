#include<stdio.h> 
#include<vector> 
#include<utility> 

#define MAXS 100000
#define MAXINT 0x7fffffff

using namespace std; 

typedef vector<int> graph ; 

graph * gp = new graph[MAXS]; 

int parent[MAXS] ; 
bool vtd[MAXS]; 

void dfsRec(int source) { // accumulators or so must be given as addresses since it is recursive
	
	// here just visited node source
	
	for(int el : gp[source] ) 
		if ( !vtd[el] ) { 
			vtd[el] = true; parent[el] = source; 

			dfsRec(el ); 
		}
	// here finished visiting subtree rooted at node source 
}

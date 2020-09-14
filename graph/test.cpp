#include<stdio.h> 
#include<vector> 
#include <utility> 
#include<unordered_map> 

#define MAXS 30 
#define MAXW 100
#define BIG 1000

using namespace std; 

vector < pair<float, int > > *graph = new vector< pair<float, int> > [MAXS] ; 
vector < pair<float, int > > *revGraph = new vector< pair<float, int> > [MAXS] ;

bool vtd[MAXS] , resp[BIG] ; 
int branches[MAXS] , parent[MAXS], term [MAXS];// term time is the only relevant
float cost[MAXS] ; 
unordered_map< char*, int > mp ; 


void dfsRec(int *time, int source, vector< pair<float, int> > *graph) { 
	*time += 1; 
	vtd[source] = true; 

	for( pair<float, int> ady : graph[source] )  
		if ( ! vtd[ ady.second ] ) {
			dfsRec ( time, ady.second , graph) ; 
			branches[ ady.second ] = source; 
		}

	*time += 1; 
	term[source ] = *time; 
}

void dfsVisit(int size, vector< pair< float, int > > *graph, vector<int> dir) { 
	int time = 0 ;

	for(int i : dir ) 
		if ( !vtd[i] ) 
			dfsRec( &time, i, graph); 
}

void invGraph(int size) { 
	for(int i=0; i<size; i++) 
		for( pair<float, int> ady : graph[i] ) 
			revGraph[ ady.second ].push_back({  ady.first, i } ); 
}

int main() { 
	
}
int test(){ 
	int n, m , cnt =0 ; 
	char wd[MAXW], u[MAXW], v[MAXW]  ; 


	while ( scanf("%d",&n) && n != 0 ) { 

		for(int i=0; i<n; i++) { vtd[i] = false; parent[i] = cost[i] = -1; } //init
		
		for (int i=0; i<n; i++) { scanf("%s",wd) ; mp.insert({wd, i} ) ; } 
		scanf("%d",&m); 

		float w; 
		for(int i=0; i<m; i++) { 
			scanf("%s %f %s", u, &w, v ) ; 
			graph[ mp[u] ].push_back ( { w, mp[v] } ) ; 	
		}

		// algorithm 


		// - find strongly connected components using dfs visit + invGraph
		// - use a representant from each strongly connected component and run bellman's
		// modified version so it perhaps finds a "negative cost cicle" within each component. 
		// - if there isn't bellman would'benn run c times where c is the number of 
		// strongly connected components. 
		//
		// This is too heavy

		//
		cnt+=1; 

		for(int i=0; i<n; i++) { graph[i].clear(); revGraph[i].clear() ; }  // cleaning
		mp.clear() ;
	}

	for(int i=0 ;i<cnt; i++) printf("Case %d: %s\n", i, (resp[i])? "Yes": "No" ) ; 
}	

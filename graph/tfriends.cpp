#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <algorithm> 

#define MAXS 100
#define MAXT 1000

using namespace std; 


vector< int > *graph = new vector<int> [MAXS] ;
vector< int > *revGraph = new vector<int> [MAXS] ;

bool vtd[MAXS]; 
int term [MAXS], resp[MAXT], parent[MAXS]; 
char line[MAXS] ; 


void dfsRec ( int current, int *time, vector<int> graph[] ) {

	*time += 1; 
	vtd[current] = true; 

	for( int ady : graph[ current ] )  
		if( ! vtd[ady] ) {
			parent[ ady ] = current; 
			dfsRec ( ady, time, graph) ; 
		}

	*time += 1; 
	term[ current ] = *time; 
} 

void dfsVisit ( int size,  vector<int> order, vector<int> graph[]) {

	int time = 0 ;
	
	for(int ord : order ) 
		if ( ! vtd[ord] )  
			dfsRec( ord, &time, graph) ;
}

int main() { 
	int n, t, k,cnt;  
	vector<int> order; 
	vector< pair<int, int> > help ; 

	scanf ("%d",&t); 

	k = t ;

	while( k-- ) { 

		scanf("%d",&n); 
		
		for(int i=0 ; i<n; i++) { vtd [i] = false; parent[i] = i ; term[i] = 0 ; } //init
		cnt = 0; 

		for(int i=0; i<n; i++)  {
			scanf("%s",line); 
			for(int j=0; j<n; j++) 
				if ( line[j] == 'Y' ) {
					graph[i].push_back (j); 
					revGraph[j].push_back (i); 
				}
		}


		// algorithm goes here
		
		for(int i=0 ; i<n; i++) order.push_back(i); 

		dfsVisit(n, order, graph) ; 


		order.clear() ;

		for(int i=0; i<n ; i++) 
			help.push_back( { term[i], i} ); 

		sort( help.begin(), help.end() ) ;  

		for(int i =n-1; i>-1; i--)
		       	order.push_back( help[i].second ) ; 

		for(int i=0; i<n;i++) { vtd[i] = false; parent[i] =i ; term[i] = 0;  } 
		//reseting for 2nd pass

		dfsVisit(n , order, revGraph) ;


		for(int i=0 ;i<n; i++) //counting scc
			if ( parent[i] == i) 
				cnt+=1; 
		//
		
		resp[t-k-1] = cnt; 

		for(int i =0 ; i<n; i++) { graph[i].clear(); revGraph[i].clear() ; } //cleanup

		order.clear(); help.clear(); 
	}

	for(int i=0; i<t; i++) printf("%d\n",resp[i]); 
}

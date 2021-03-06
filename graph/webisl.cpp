#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <set> 
#include <map> 
#include<deque> 

#define MAXS 10000000

using namespace std; 

typedef vector<int> vi ;

vi *graph = new vi[MAXS]; 
set <int> *help = new set<int> [MAXS]; 
map<int, int> corresp, toRep; 
deque<int> cc; 

bool vtd[MAXS]; 
int disc[MAXS], low[MAXS]; 

void dfsRec (int source, int *time, int *cnt) { // tarjan's alternative for scc

	vtd[ source ] = true; 

	*time +=1; 
	disc[source] = low[source] =  *time; 

	for(int ady : graph[source] )  
		if ( !vtd[ady] ) { 
			cc.push_back(ady); 

			dfsRec( ady, time, cnt) ; 
			low [ source ] = min (low[source], low[ady] ) ; 
		}
		else  
			for(int el : cc) 
				if ( el == ady ) {
					low[source] = min ( disc[ady], low[source] ) ; 
					break; 
				}

	if ( low[source] == disc[source] ) {
		for(int i=cc.size()-1; i>-1 ;i--) {
			help[ *cnt ].insert( cc[i] ) ; 
			toRep[ cc[i] ] = source; 
			cc.pop_back(); 			// deque allows reverse query and popping

			if ( cc[i] == source ) 
				break; 
		}
		
		corresp[source] = *cnt; 
		*cnt += 1;
	} 


}

	

int main () { 
	int n,m, u, v, k ; 

	scanf("%d %d",&n, &m); 

	for(int i=0; i<n; i++) vtd[i] = false;  
	k = m ;
	while (k--) { 
		scanf("%d %d",&u, &v); 
		graph[u].push_back(v); 	
	}	

	// algorithm goes here
	
	int time =-1 , cnt = 0; 
	for(int i=0 ;i<n; i++)  
		if ( !vtd[i] ) {
			cc.push_back(i); 
			dfsRec( i , &time , &cnt) ; 
		}

	for(int i=0 ;i<n; i++) 
		printf("%d\n", *help[ corresp[ toRep[i] ] ].begin() ) ; // use index to query respective scc set

	//

}

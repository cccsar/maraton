#include<stdio.h> 
#include<vector> 
#include<utility> 

#define MAXS 100000
#define MAXINT 0x7fffffff

using namespace std; 

typedef vector<int> vi; 

vi *graph = new vi [MAXS], *scc = new vi [MAXS]; 
vi current; 

int low[MAXS], disc[MAXS]; 
bool vtd[MAXS]; 

void dfsRecTarjan(int source, int *time, int *cnt) { 
	*time +=1; 

	current.push_back( source )  ;

	disc[source] = low[source] = *time; 

	for(int el : graph[source] ) 
		if ( !vtd[el]  ) { 
			vtd[el] = true; 

			dfsRecTarjan(el, time, cnt) ; 

			low[source] = min( low[source], low[el] ); 
		}
		else  // check if "back edge" or "cross edge" :)
			for(int cand : current) 
				if ( cand == el ) {
					low[source] = min (low[source],disc[el]); 
					break; 
				}

	if ( disc[source] == low[source] ) { // if low == disc then there's a "head" of scc
		while( current.back() != source )  { 
			scc[*cnt].push_back( current.back() ); 
			current.pop_back(); 
		}
		scc[*cnt].push_back(source) ; 
		current.pop_back(); 

		*cnt+=1; 
	}
}

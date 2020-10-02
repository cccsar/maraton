#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<queue> 
#include<set>

#define MAXS 10000

using namespace std; 

typedef vector<int> grp; 

grp * graph = new grp [MAXS]; 
set<int> * cand = new set<int> [MAXS]; 
queue<int> nextQ; 
grp * cycles = new grp[MAXS]; 

bool opn[MAXS], cld[MAXS]; 
int dist[MAXS], parent[MAXS]; 

void bfs(int source) { 
	int help ; 
	
	nextQ.push( source ) ; 
	opn[source] = true; dist[source] = 0; parent[source] = source; 

	while ( !nextQ.empty() )  { 
		help = nextQ.front(); 
		nextQ.pop(); 

		cld[help] = true;  

		for(int ady : graph[help])  
			if ( !cld[ady] && !opn[ady] ) { 
				opn[ady] = true; dist[ady] = dist[help] + 1; parent[ady] = help ;
				nextQ.push( ady ) ; 	
			}
			else 
				if ( ady != parent[help] )  { 
					if ( cand[ady].find( help ) == cand[ady].end() ) 
						cand[help].insert( ady ) ; 		
				}
	}
}

int  drawCycle(int size) { 
	int ind =0  ;
	for(int i=0; i<size; i++) 
		for(int el : cand[i] ) { 
			int imp = ( dist[i] > dist[el])? i : el, oth = (dist[i] > dist[el])? el : i;  

			while ( dist[imp] != dist[oth] ) { // level largest of elements with shorter
			       cycles[ind].push_back ( imp ) ; 
			       imp = parent[imp] ; 
			}

			while ( imp != oth ) { // add elements to the cycle as they have different ancestors
				cycles[ind].push_back( imp ); cycles[ind].push_back ( oth ) ; 
				imp = parent[imp] ; oth = parent[oth] ; 
			}

			cycles[ind].push_back (imp) ; 
			
			ind +=1; // increase ind only as a candidate is considered ( there are i's where is not ) 
		}

	return ind; 
}

int main() { 
	int n, m, u, v; 

	scanf("%d %d",&n, &m); 

	for(int i =0; i<n; i++) { dist[i] = 0; opn[i] = cld[i] = false; }

	for(int i=0 ;i<m ;i++) { 
		scanf("%d %d",&u, &v); 
		graph[u].push_back (v); 
		graph[v].push_back(u); 
	}

	bfs(0); 
	
	int nCycles = drawCycle(n); 

//	for(int i=0 ;i<n; i++) { 
//		cout<<i<<": "; 
//		for(int el : cand[i]) printf("%d ", el ); 
//		cout<<endl; 
//	}

	for(int i=0;i<nCycles; i++) { 
		cout<<i<<": "; 
		for(auto j=cycles[i].begin(); j != cycles[i].end(); j++)  
			printf("%d ",*j); 
		cout<<endl; 
	}


}

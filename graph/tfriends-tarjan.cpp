#include <stdio.h> 
#include<iostream> 
#include<vector> 
#include<stack>

#define MAXS 100
#define MAXT 1000

using namespace std; 

typedef vector<int> vi; 

vi *graph = new vi [MAXS];
vi nodes; 
 
char line[MAXS]; 
short int low[MAXS], disc[MAXS]; 
bool vtd[MAXS] ; 

int resp[MAXT];


void dfsRecTarjan(short int source, short int *time, short int *cnt, vi graph[] ) {
	*time +=1 ;

	disc[source] = low[source] = *time; 
	nodes.push_back( source ); 

	for(short int ady : graph[source]) { 
		if( !vtd[ady] ){ 
			vtd[ady] = true; 
			
			dfsRecTarjan(ady, time, cnt, graph); 

			low[source] = min(low[source], low[ady]); 
		}
		else  
			for(short int el : nodes) 
				if ( el == ady ) { 
					low[source] = min( low[source], disc[ady]) ; 
					break ;
				}
	}

	if ( low[source] == disc[source] ) {  // then it is a head of tree?
		while ( nodes.back() != source)  
			nodes.pop_back(); 

		nodes.pop_back(); 
		*cnt += 1; 
	}

}

int main() { 
	short int n, t, k; 

	scanf("%hd ",&t); 

	k = t; 

	while ( k -- ) { 

		scanf("%hd ", &n); 

		for(short int i=0; i<n; i++) { // init
			vtd[i] = false;
			low[i] = disc[i] = 0; 	       
		} 


		for(short int i =0 ; i<n; i++) { 
			scanf("%s",line); 
			for(short int j=0; j<n; j++) 
				if ( line[j] == 'Y' ) 
					graph[i].push_back(j);
		}

		// algorithm goes here

		short int time = -1, cnt = 0; 	
		for(short int i=0; i<n; i++) 
			if ( !vtd[i] ){
				vtd[i] = true; 
				dfsRecTarjan(i, &time, &cnt, graph); 
			}


		resp[t-k-1] = cnt ; 

		//

		for(short int i=0 ;i<n; i++) // cleaning
			graph[i].clear(); 

	}

	for(short int i=0; i<t; i++) printf("%d\n",resp[i]); 
}

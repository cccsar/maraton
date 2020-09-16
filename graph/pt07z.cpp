#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <queue> 

#define MAXS 10000

using namespace std; 

typedef vector<int> vi; 
typedef pair<int, int> pi; 

vi *graph = new vi [MAXS]; 
priority_queue< pi > myQ; 

bool vtd[MAXS]; 


void dfsRec( int source, int *depth ) { 

	myQ.push ( { *depth, source } ) ; 
	vtd[source] = true;
	
	for(int ady : graph [ source ] ) 
		if ( ! vtd[ady] ) {
			*depth += 1; 
			dfsRec ( ady, depth ) ;
			*depth -= 1;
		}

}

int main () { 
	int n, k ; 

	scanf("%d",&n); 
	k = n-1; 

	for(int i=0; i<n; i++) vtd[i] = false; 

	int u,v ;
	while (k--){ 
	      	scanf("%d %d",&u,&v); 
		graph[u-1].push_back (v-1) ; 
		graph[v-1].push_back(u-1);
	}

	//algorithm goes here
	int depth = 0 ;
	dfsRec(0, &depth) ; 	// do a dfs traversal to obtain currently longest path using pqueue

	int newS = myQ.top().second; 

	while ( ! myQ.empty() ) myQ.pop(); //empty pqueue
	for(int i=0 ;i<n; i++) vtd[i] = false; 

	depth = 0; 

	dfsRec( newS, &depth) ; // make a second traversal to compute actual longest path
	//

	cout<<endl; 
	printf("%d\n", myQ.top().first ) ; 

}

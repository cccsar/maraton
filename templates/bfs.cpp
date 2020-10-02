#include<iostream> 
#include<stdio.h> 
#include<queue> 

#define MAXS 10000
#define MAXINT 0x7fffffff

using namespace std; 

typedef vector<int> vi ; 

vi *graph = new vi[MAXS]; 
bool vtd[MAXS]; 
int parent[MAXS], cnt[MAXS];

void bfs ( int source ) {
	queue<int> myQ; 
	int dum; 

	vtd[source] = true; cnt[source] =0 ;
	myQ.push(source); 

	while ( !myQ.empty() ) { 
		 dum = myQ.front(); 
		 myQ.pop(); 
			
		 for(int ady : graph[dum] )  
			if (  !vtd[ady] ) { // same as dfsRec, if not vtd, then visit
				vtd[ady] = true; parent[ady] = dum; cnt[ady] = cnt[dum] + 1; 

				myQ.push( ady ) ; 
			}
	}
}

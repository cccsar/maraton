#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <queue> 
#include <set> 

#define MAXS 1000

using namespace std; 

typedef vector<int> vi ;

vi *graph = new vi[MAXS]; 
set <int> *help = new set<int> [MAXS]; 

bool vtd[MAXS]; 
int parent[MAXS], disc[MAXS], low[MAXS]; 

int rnk[MAXS], group[MAXS]; 

int find ( int e ) { 
	int dum = e ; 

	while ( group[dum] != dum ) 
		dum = group [dum] ; 

	if ( dum != e ) 
		group[e] = dum; 

	return dum; 
}

void onion ( int u, int v) { 
	int x = find(u), y = find(v); 

	if ( x != y ) { 
		if ( rnk [x] >= rnk[y] ) { 
			group[y] = x; 

			if ( rnk[x] == rnk[y] ) 
				rnk[x] +=1; 
		}
		else 
			group[x] = y; 
	}
}

void dfsRec(int source, int *time ) {// tarjan imp
	*time +=1 ;

	disc[source] = low[source] = *time; 
	vtd[source] = true; 
	
	for(int ady : graph[source] ) { 
		if ( !vtd[ady] ) { 
			parent[ady] = source; 
			dfsRec(ady, time) ; 	
			low [ source ] = min ( disc[source], low[ady] ) ; 
		}
		else
			low [ source] = min ( disc[ady], low[source] ) ; 	
	}
} 

int main () { 
	int n,m, u, v, k ; 

	scanf("%d %d",&n, &m); 

	for(int i=0; i<n; i++) { vtd[i] = false; parent[i] = group[i] = i; rnk[i] = 0 ;}  
	k = m ;
	while (k--) { 
		scanf("%d %d",&u, &v); 
		graph[u].push_back(v); 	
	}	

	// algorithm goes here
	
	int time =-1 ; 
	for(int i=0 ;i<n; i++)  
		if ( !vtd[i] ) 
			dfsRec( i , &time ) ; 

//	cout<<"disctime: \n";//db
//	for(int i=0;i<n; i++) printf("%d ",disc[i]); 
//	cout<<endl; 
//
//	cout<<"parents: \n";
//	for(int i=0;i<n; i++) printf("%d ",parent[i]); 
//	cout<<endl; 
//
	cout<<"low: \n";
	for(int i=0;i<n; i++) printf("%d ",low[i]); 
	cout<<endl; 
//
//

	for(int i=0 ;i<n; i++) onion ( i, low[i]); 

	for(int i=0; i<n; i++) printf("%d ",group[i]); 
	cout<<endl; 

	int current;
	for(int i=0; i<n; i++) { 
		current = find( i ) ; 

		help[ current ].insert(i); 
	}


	for(int i=0; i<n ;i++) printf("%d\n",*help[ find (i ) ].begin() ) ; 
		
	return 0; 
	//
	

}

#include <stdio.h> 
#include <unistd.h> // cstuff 
#include <iostream>
#include <string.h> 
#include <queue> 
#include <utility> 
#include <vector> 
#include <stack> 

#define MAXS 10000
#define MAXINT 20394823

using namespace std; 

typedef pair <int, int> pi; 
typedef pair< int, pair<int, int> > pii; 
typedef vector < int > vi ; 
typedef vector< pi > vii;  
typedef priority_queue < pii, vector<pii>, greater <pii> > minQ; 


//for kruskal 
//int parent[MAXS] ; 
//int rnk[MAXS] ; 
//int tr[MAXS] ; // branching

int find ( int x , int parent[] ) { 
	int dum = x; 

	while ( parent[dum] != dum )  
		dum = parent[dum]; 

	if ( parent[x] != dum )  
		parent[x] = dum;

	return dum; 
}

void onion ( int a, int b, int rnk[], int parent[], int tr[] ) { 
	int x = find ( a, parent ); 
	int y = find ( b, parent ); 

	if ( x != y ) {
		if ( rnk[x] >= rnk[y] ) { 
			parent[y] = x; 
		

			if ( rnk[x] == rnk[y] )   
				rnk[x] += 1; 

			tr [b] = a ;
		}
		else  { 
			parent[x] = y ; 				
			tr[a] = b; 
		}

	}
}

void kruskal (minQ & myQ, int rnk[], int parent[] , int tr[] ) { 
	pii dum; 
	while ( ! myQ.empty() ) { 
		dum = myQ.top() ; 
		myQ.pop(); 
		onion ( dum.second.first, dum.second.second, rnk, parent, tr) ; 
	}	
}


//for prim 
//int vtd[MAXS] ; 

void prim (vii graph[] , int vtd[], int root , int size) { 
	minQ myQ; 
	pii dum; 

	myQ.push({0,{ root, root } }); 

	while ( ! myQ.empty() ) { 
		dum = myQ.top(); 
		myQ.pop(); 

		if ( vtd[ dum.second.first ] == -1 ) { 

			vtd[ dum.second.first ] = dum.second.second; 

			for (pi ady : graph[ dum.second.first ] )  
				if ( vtd[ ady.second ] == -1 )  
					myQ.push( { ady.first, { ady.second, dum.second.first }  } ) ; 
		}
	}
	
} 


//for dfs 
//int vwd[MAXS] ; 

void dfsRec (vi graph [] , int vtd[] , int root ) { 
	
	for ( int ady : graph[root] )  
		if ( vtd[ady] == -1 )  { 
			vtd[ady] = root; 
			dfsRec ( graph, vtd, ady ) ; 
	}
}

//for dfs visit
int parent[MAXS] ; 
int disc[MAXS] ; 
int term[MAXS] ; 
int color[MAXS] ; 
#define WHITE 0 
#define GREY 1
#define BLACK 2

void dfsColor (int current, int *time, vi graph[], int disc[], int term[], int color[], int parent[]) {
	*time += 1; 
	disc[current] = *time; 
	color[current] = GREY ;

	for( int ady : graph[current] ) 
		if ( color[ady] == WHITE ) { 
			parent[ady] = current; 
			dfsColor( ady, time, graph, disc, term, color, parent) ; 	
		}

	*time += 1; 
	term[current] = *time; 
	color[current] = BLACK ;
} 

void dfsVisit (int size, vi graph[], int disc[], int term[], int color[], int parent[] ) { 
	int time = 0; 

	for (int i=0; i<size; i++)  
		if ( color[i] == WHITE) 
			dfsColor(i, &time, graph, disc, term, color, parent ) ; 

}

vi*  reverseG(vi graph[] , int size ) {
	vi *newGraph = new vi [MAXS] ; 
	
	for (int u=0; u<size; u++) 
		for (int v : graph[u] )  
			newGraph[v].push_back(u); 

	return newGraph; 
} 

void compConex( vi graph[], int size , int paps[] ) { 
	vi *revGraph ;

	dfsVisit(size, graph, disc, term, color, parent );

	revGraph = reverseG(graph, size); 		

	//define and init new set of arrays
	int bdisc[MAXS], bterm[MAXS] , bcolor[MAXS] ;
	for (int j=0; j<size; j++) bdisc[j] = bterm[j] = bcolor[j] = 0 ;

	int time = 0; 
	for (int i=size-1; i>=0; i--)   
		if ( color[ term[ i ] ] == WHITE) 
			dfsColor(i, &time, revGraph, bdisc, bterm, bcolor, paps) ; 

}

void branchRecovery(int branches[] , int size) {
	stack<int> revPath; 
	int crt; 
	
	for (int i=0; i<size; i++ ){ 

		crt = i ;
		while ( branches[crt] != crt ) { 
			revPath.push( crt );   
			crt = branches[crt] ;
		}
		revPath.push ( crt ); 
	
		while ( ! revPath.empty() ) {
			printf("%d ",revPath.top() ) ; 
			revPath.pop(); 
		}	       
		cout<<endl ;
	
	}

} 


 

int main () { 
	int n, m, u, v, time = 0; 
	vi * graph = new vi [MAXS] ; 
	int paps[MAXS] ; 

	scanf("%d %d",&n, &m) ;

	for (int i=0; i<n ; i++) { 
		disc[i] = term[i] = color[i] = disc[i] = WHITE ;
      		parent[i] = paps[i] = -1;  
	}  

	for (int j=0; j<m; j++ ){
		scanf("%d %d",&u, &v) ;
		graph[u].push_back( v ) ; 
	}

	compConex( graph, n, paps)  ;

	branchRecovery (paps, n ) ; 	

}

#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <queue> 
#include <map> 

#define MAXS 100000

using namespace std; 

typedef pair<int, int> pi; 
typedef vector< int > vi; 


vi *graph, *revGraph, *redGraph; 
priority_queue< pi > myQ; 
map <int, int> rel; 

int parent[MAXS], term[MAXS]; 
bool vtd[MAXS]; 

int rnk [MAXS], group[MAXS]; 

void dfsRec(int *time, int source, vi graph[]) {
	*time +=1; 

	vtd[source] = true; 

	for(int v : graph[source] )  
		if ( ! vtd[ v ] ) { 
			parent[ v ] = source; 
			dfsRec (time, v, graph) ; 
		}

	*time +=1; 
	term [ source ] = *time ; 
} 

int find (int e ) {
	int dum = e; 

	while ( dum != group[dum] ) 
		dum = group[dum] ;
			
	if ( dum != e ) 
		group[e] = dum; 

	return dum; 
}

void onion (int u, int v) {
	int x , y; 

	x = find(u), y = find (v); 

	if( x != y ) {
		if ( rnk[x] >= rnk[y] ) { 
			group[ y] = x; 
			if ( rnk[x] == rnk[y] ) 
				rnk[x] +=1; 
		}
		else
			group[x] = y; 
	}
} 

void backGraph( int size, vi graph[] , vi revGrahp[] ) { 
	
	for(int u=0; u<size; u++) 
		for(int v : graph[u]) 
			revGraph[v].push_back(u) ; 
}

int main() { 
	int n, m, u, v; 

	graph = new vi[MAXS], revGraph = new vi[MAXS], redGraph = new vi[MAXS]  ; // init

	scanf("%d %d",&n, &m); 

	for(int i=0 ;i<n; i++) { 
		parent[i] = i ; term[i] = 0 ; vtd [i] = false; 
		rnk[i] = 0 ; group[i] = i; 		
	}


	for(int i=0; i<m; i++) {
		scanf("%d %d", &u, &v) ; 

		graph[u-1].push_back (v-1) ; 
		revGraph[v-1].push_back (u-1); 
	}

	int time = 0; 	
	for(int i=0; i<n; i++)  
		if( !vtd[i] ) 
			dfsRec( &time, i, graph); 
	

	for(int i=0; i<n; i++) { 
		myQ.push ( { term[i], i} ) ; // fill pq for reverse traversal 
		term[i] = 0; parent[i] = i ; vtd[i] = false; // reset
	}

	time = 0 ; 


	pi help; 
	while ( !myQ.empty() )  { // perform reverse-term traversal on reverse graph
		help = myQ.top(); 
		myQ.pop(); 

		if ( ! vtd[ help.second ] )    
			dfsRec( &time, help.second, revGraph) ; 
	}
	// up here : O( n + m ) 


	int cnt = 0; 
	for(int i=0 ; i<n; i++) 
		onion ( i , parent[i] ) ; //better tree for queries

	for(int i=0; i<n; i++) 
		if ( group[i] == i ) {  // save a map for relating the i-th component
					 // representative with the i-th natural number (0<=i<#scc) 
			rel[ i ] = cnt ;	
			cnt +=1; 
		}

	int x, y; 
	for(int u=0; u<n; u++) { 	// create reduced graph
		for(int v : graph[u] ) { 
			x = find (u); y = find(v); 
			if ( x != y )    
				redGraph[ rel[x]  ].push_back ( rel[y] ) ; 				
			
		}
	}
		

	int fldC = 0 , imp ; 
	for(int i=0 ; i<cnt; i++ )  	//find vertex with out-degree == 0
		if ( redGraph[i].size() == 0 ) { fldC +=1; imp = i ; }


	// if the # floods > 1 then there's no universal flood
	
	if ( fldC == 1 ) { 
		int def; 
		for( pi help : rel )  //find the original representative of such scc
			if ( help.second == imp ) { // it is guaranteed to be found
				def = help.first; 
				break; 
			}

		for(int i =0; i<n; i++) 
			if ( find( group[i] ) == def ) //find all vertex in that scc
				myQ.push( {n-i,i} )  ;

		printf("%d\n",myQ.size()); 
		while ( !myQ.empty() ) { 
			printf("%d ", myQ.top().second + 1) ; 
			myQ.pop(); 
		}
		cout<<endl; 
	}
	else  
		cout<<"0\n";
}



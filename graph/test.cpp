#include<stdio.h> 
#include<iostream> 
#include<algorithm> 
#include<set> 
#include<map> 
#include<queue> 
#include<vector>

#define MAXS 10000

using namespace std;

typedef vector<int> vi; 
typedef pair<int, int> pi ;

vi *graph = new vi[MAXS];

int height[MAXS], parent[MAXS]; 


void bfs (int source) {
	queue<int> myQ; 
	int dum; 

	myQ.push( source ) ; 
	height[source] = 0 ; parent[source] = source; 

	while ( !myQ.empty() ) { 
		dum = myQ.front(); 
		myQ.pop(); 

		for(int ady : graph[dum] ) 
			if ( height[ady] == -1 ){
				height[ady] = height[dum] +1; 
				parent[ady] = dum; 			

				myQ.push( ady ) ; 
			}
	}
}

int lca(int u, int v) { 
	pi p, q, r, s; 
	p = { height[u], u }, q = { height[v], v} ;
	r = min(p, q), s = max(p,q); 

	while ( s.first != r.first ) { // equalize heights
		s.second = parent[s.second]; 
		s.first -= 1; 
	}

	while ( r.second != s.second) { // equalize ancestry
		s.second = parent[s.second]; 
		s.first -=1; 

		r.second = parent[r.second]; 
		r.first -= 1; 
	}	
	
	return r.second; 

}

int main() { 
	int n,m, u,v; 

	scanf("%d %d",&n, &m) ;

	for(int j=0; j<n; j++) { height[j] = -1; parent[j] = j; } // init

	for(int i=0 ;i<m; i++) { // input is tree
		scanf("%d %d",&u, &v); 

		graph[u].push_back(v); 
		graph[v].push_back(u); 
	}


	bfs(0); 

	while ( true )  {
		scanf("%d %d\n",&u,&v); 
		if ( u == -1 || v == -1 ) 
			break ;
		printf("u: %d v: %d lca(u,v): %d\n",u, v,lca(u,v)); 
	}
}


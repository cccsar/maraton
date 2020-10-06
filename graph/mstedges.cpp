#include<stdio.h>
#include<iostream> 
#include<vector> 
#include<set> 
#include<map> 
#include<queue> 

#define MAXN 100001
#define MAXINT 0x7fffffff

#define ALO 0 
#define ANY 1
#define NONE 2

using namespace std; 

typedef pair<int, int> pi ;
typedef vector<pi> graph; 

graph *initial = new graph[MAXN]; 
graph *tree = new graph[MAXN]; 
vector<pi> candidates; 
map< pi, pi> edges; // map from edges to index and weight | cond(fst<snd)
priority_queue< pair<int, pair<int, int> > > myQ; 

int state[MAXN], deg[MAXN]; 
int parent[MAXN], rnk[MAXN];
int height[MAXN], pops[MAXN]; 
bool vtd[MAXN]; 


int find(int el) {
	int cc = el ;

	while ( cc != parent[cc] )
		cc = parent[cc]; 

	parent[el] = cc; 

	return cc; 
} 

void onion(int u, int v){
	int x = find(u), y = find(v); 

	if (x != y) {
		if (rnk[x] >= rnk[y] ) { 
			parent[y] = x; 
			if (rnk[x] == rnk[y])
				rnk[x] +=1; 
		}
		else 
			parent[x] = y; 
	}
}

void kruskal(int size) {
	int cnt = size - 1 ; 
	pair<int, pi>  cc, last; 

	while ( !myQ.empty()  ) {
		cc = myQ.top(); 
		myQ.pop(); 

		if( find(cc.second.first) != find(cc.second.second) ) { 
			onion(cc.second.first, cc.second.second); 

			tree[cc.second.first].push_back( { -cc.first, cc.second.second} ); 
			tree[cc.second.second].push_back( { -cc.first, cc.second.first} ) ; 

			state[edges[{cc.second.first, cc.second.second}].first]  = ANY; 

			cnt -=1;
			if ( cnt == 0) 
				last = cc; // I hope this is not a pointer

		}
		else  {
			if ( cnt != 0 || cc.first == last.first) 
				candidates.push_back( {cc.second.first, cc.second.second} ); 	
		}

	}

} 

void bfs(int source) {
	int curr; 
	queue<int> next; 

	next.push(source); 
	height[source] = 0; pops[source] = source;  

	while ( !next.empty() ) { 
		curr = next.front(); 
		next.pop(); 
	
		for(pi v : tree[curr])  
			if( height[v.second] == -1 ) { 
			       	height[v.second] = height[curr] + 1; 
				pops[v.second] = curr; 

				next.push( v.second ) ; 
			}
	}
}

void lca(int u, int v) {
	const int cost = edges[{u, v}].second;  	
	const pi p = { height[u], u }, q = { height[v], v};

	int cicost; 
	pi yo, lo;
	bool chk = false; 

	yo = min(p, q), lo = max(p, q); 

	// down to equal heights
	while( yo.first != lo.first ) { 
		cicost = edges[ { min(lo.second, pops[lo.second]), max(lo.second, pops[lo.second]) } ].second ;	
		if ( cost == cicost ) {
			state[edges[{ min(lo.second, pops[lo.second]), max(lo.second, pops[lo.second]) } ].first] = ALO; 
			state[edges[{u,v}].first] = ALO; 
			chk = true; 
		}

		lo.first -= 1; lo.second = pops[lo.second]; 
	}

	// equal heights until lca
	while( yo.second != lo.second ) { 
		cicost = edges[{ min(yo.second, pops[yo.second]), max(yo.second, pops[yo.second]) } ].second ;	
		if ( cost == cicost ) {
			state[edges[{ min(yo.second, pops[yo.second]), max(yo.second, pops[yo.second]) } ].first] = ALO; 
			if (!chk) {
				state[edges[{u,v}].first] = ALO; 
				chk = true; 
			}
		}

		yo.first -= 1; yo.second = pops[yo.second]; 


		cicost = edges[{ min(lo.second, pops[lo.second]), max(lo.second, pops[lo.second]) } ].second ;	
		if ( cost == cicost ) {
			state[edges[{ min(lo.second, pops[lo.second]), max(lo.second, pops[lo.second]) } ].first] = ALO; 
			if ( !chk ) {  
				state[edges[{u,v}].first] = ALO; 
				chk =true; 
			}
		}

		lo.first -= 1; lo.second = pops[lo.second]; 
	}
}
	

int main() {
	int n,m ,u,v,w; 

	scanf("%d %d",&n, &m); 

	for(int i=0 ;i<m ;i++) { 	// init
		state[i] = NONE ;
		if( i<n ) { 
			rnk[i] = 0 ; parent[i] = i; 
		       	deg[i] = 0;
			height[i] = -1; 
		}
       	} 

	for(int i=0; i<m; i++) { 
		scanf("%d %d %d",&u, &v, &w); 
		initial[u-1].push_back({w,v-1}); 
		initial[v-1].push_back({w,u-1}); 

		deg[u-1] +=1; deg[v-1] +=1 ;
		edges[{min(u-1,v-1), max(u-1,v-1)}] = { i , w } ;
	}


// algorithm goes here

	// delete vertix until there are none of deg == 1
	if ( m == n-1) 
		for(int i=0; i<m; i++) printf("any\n"); 
	else { 
	
		queue<int> degs; 
		for(int i=0; i<n; i++)  
			if ( deg[i] == 1 ) 
				degs.push(i); 

			
		int dum, ind; 
		while( !degs.empty()) { 
			dum = degs.front(); 
			degs.pop(); 
	
			deg[dum] -= 1; // those with deg == 0 were deleted
	
			for(pi ady : initial[dum] ) { 
				if ( deg[ady.second != 0] ) 
					deg[ady.second] -= 1; 
	
				ind = edges[{min(dum,ady.second), max(dum,ady.second)}].first; 
				state[ind] = ANY; // update deleted edge to ANY state
	
				if ( deg[ady.second] == 1 )  
					degs.push( ady.second ) ; 
			}
						
		}
		// O(m*log(m)) when there are not cycles
	
		// update queue ignoring deleted edges
		
		int nel = 0; 
		for(int j=0; j<n; j++) 
			for(pi ady : initial[j]) 
				if ( j < ady.second && deg[j] != 0 && deg[ady.second] != 0 )  {
					nel +=1; 
					myQ.push( { -ady.first, { j, ady.second } } ); 
				}
		//(m*log(m)) 

		for(int i=0 ;i<n; i++) initial[i].clear(); 
		
		// compute mst with remaining graph (over new size) , and keep candidates for any mst
		
		kruskal(nel); 
	
		// use bfs, to help computing lca of candidates and in the process, update state 

		int sc; 
		for(int i=0; i<n; i++) 
			if ( deg[i] != 0 ) {  // choose non deleted node
				sc = i ; 
				break; 
			}	

		bfs(sc); 
		// O(n)
	
		for(pi el : candidates ) 
			lca(el.first, el.second); 
		// O(not n)
	}
	
	//
	
	for(int i=0; i<m; i++) 
		printf("%s\n", state[i] == ALO? "at least one": (state[i] == ANY? "any" : "none")); 

}

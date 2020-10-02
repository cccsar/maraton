#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<queue> 
#include<stack> 
#include<map>
#include<set> 

#define MAXS 100000

#define EXTERNAL 0
#define EXCHANGEABLE 1
#define EXCLUDED 2

using namespace std; 

typedef pair<int, int> pi; 
typedef pair<int, pi> pii; 
typedef vector<pi> wgraph; 
typedef vector<int> graph;

wgraph * tree = new wgraph[MAXS]; 
int deg[MAXS];
// before vertix deletion

priority_queue< pii, vector<pii>, greater<pii> > myQ; 
map< pi, int > results_index; 
multiset<int> weights; 

int rnk[MAXS], parent[MAXS]; // For kruskal DSU
int pow[MAXS], group[MAXS];  // for edgeFS DSU

int results[MAXS]; 

:x
	int dum = el ;

	while (dum != parent[dum] ) 
		dum = parent[dum]; 

	if ( dum != el ) 
		parent[dum] = dum; 

	return dum; 
} 

void onion(int u, int v, int parent[], int rnk[]) {
	int x = find(u, parent), y = find(v, parent); 

	if ( x != y ) { 
		if ( rnk[x] >= rnk[y] ) { 
			parent[y] = x; 
			if ( rnk[x] == rnk[y] ) 
				rnk[x] +=1; 
		}
		else 
			parent[x] = y; 
	}
}

void kruskal(int size ) {
	int cnt = 0; 
	pii dum; 

	while ( cnt != size - 1) { 
		dum = myQ.top(); 
		myQ.pop(); 

		if ( find (dum.second.first, parent) != find (dum.second.second, parent) ) { 
			cnt += 1; 

			tree[dum.second.first].push_back({dum.first,dum.second.second});// create tree for ady checking later
			tree[dum.second.second].push_back({dum.first,dum.second.first}); 

			onion(dum.second.first, dum.second.second, parent, rnk); 

			weights.insert( dum.first ) ; // expand set of weights belonging to mst
		}
		// tree will contain the mst and myQ will contain cicle edges (candidates to exchangeable)

	}
}

bool edgeFS(pii & cand) { 
	
	if ( weights.find( cand.first ) != weights.end() )  
		for(vector<pi> adys : { tree[cand.second.first], tree[cand.second.second] } ) // visiting a pair of vertix ady
			for(pi ady : adys) { 
				if ( ady.first == cand.first ) 
					return true; 
				else { 
					// query PQ for an edge with a weight of the 
					// current adyacent that hasn't been considered
					// if there is such edge, join the set and check for cycles, 
					// if there's no cycle repeat edgeFS over it, otherwise 
				}
			// join any adyacent to someCandidate and if found a loop return true
			}
}

int main () { 
	int n,m,u,v,w;

	scanf("%d %d",&n, &m); 


	for(int i=0 ;i<n; i++) { rnk[i] = 0; parent[i] = i; deg[i] = 0 ; } // init

	for(int j=0; j<m ; j++) { 
		scanf("%d %d %d",&u, &v, &w); 

		tree[u].push_back({w,v});  // This inital graph is only for checking adyacencies
		tree[v].push_back({w,u});  // while deleting 1 degree vertix, and building the remaining tree

		results_index[{min(u,v),max(u,v)}] = j;  
		results[j] = EXTERNAL ; 
		deg[u] +=1; deg[v] +=1;    
	}

	// algorithm goes here

	if ( m == n -1 )  
		for(int i=0 ;i<m; i++) printf("any\n"); 
	else { 

		stack< int > deleter; 
		bool chg = false ; 
		for(int i=0 ;i<n; i++)  
			if ( deg[i] == 1) { 
				chg = true; 
				deleter.push( i ) ; 
			}
			

		int imp, cnt = 0;
		if ( chg )   	// if there's at least a vertix with deg==1, "delete" until there are not
			while ( ! deleter.empty() ) { 
				imp = deleter.top(); 
				deleter.pop(); 

				if ( deg[imp] == 1) {  		// check for extremes of a single path
					deg[imp] -=1; cnt +=1 ;
					for(pi ady: tree[imp]) {
						deg[ady.second] -= 1; 
						if ( deg[ady.second] == 1) 
							deleter.push( ady.second ) ; 
					}
				}
				
			}
		// deg[i] == 0 will be used while creating minPQ ot ignore deleted vertix
	
	
		int sizeV = n - cnt, sizeE = 0; 
		for(int i=0 ;i<n; i++) 
			if ( deg[i] != 0)  // ignore deleted vertix
				for(pi ady : tree[i]) 
					if (deg[ ady.second] != 0) { // ignore deleted vertix
						myQ.push( { ady.first, { i, ady.second } } ) ; 				
						sizeE +=1; 
					}

		for(int i=0 ;i<n; i++) tree[i].clear(); // clear graph so it is reused as a tree
	
		kruskal ( sizeV ) ; 

//		cout<<"parent\n"; 
//		for(int i=0 ;i<n; i++) printf("%d ",parent[i]); 
//		cout<<endl; 
//		cout<<"tree\n"; 
//		for(int i=0 ;i<n; i++) 
//			for(pi ady : tree[i])
//				printf("%d %d %d\n",i,ady.second,ady.first); 
//		cout<<endl; 

		
		pii help ; 
		bool cicle = false; 
		while (!myQ.empty() ) { 
			help = myQ.top(); 
			myQ.pop(); 	
	
			cicle = edgeFS(help); 
			
		}
	}
	//
}


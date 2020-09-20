#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<queue> 


#define MAXT 5
#define MAXS 50000
#define MAXINT 1000000000000000001 

using namespace std; 

typedef pair<long long, pair<int, int > > pii; 
typedef pair<long long, int> pi; 

priority_queue<pii>  myQ; 
vector<pi> *tree = new vector<pi> [MAXS]; 

long long resp[MAXT] ;

int rnk[MAXS], group[MAXS]; //dsu stuff

int parent[MAXS];// dfs stuff 
long long cost[MAXS]; 
bool closed[MAXS]; 


int find (int el ) { 
	int dum = el; 

	while( dum != group[dum] ) 
		dum = group[dum]; 

	if( el != dum) 
		group[el] = dum; 

	return el ;	
}

void onion(int u, int v) { 
	int x = find(u), y = find(v); 

	if( x != y ) { 
		if (rnk[x] >= rnk[y]) { 
			group[y] = x; 

			if(rnk[x] == rnk[y])
				rnk[x] +=1; 
		}
		else
			group[x] = y; 
	}	

}

void bfs(int source) { 
	queue<int> qq; 
	int cc; 

	qq.push( source ) ; 

	while ( !qq.empty() ) { 
		cc = qq.front(); 
		qq.pop();  

		closed[cc] = true; 

		for(pi ady : tree[cc])  
			if ( !closed[ady.second] && parent[ady.second] == -1 ) { 
				parent[ady.second] = cc; 
				cost[ady.second] = min( cost[cc], ady.first ) ; 
				qq.push( ady.second ) ; 
			}	
	}	
}

void dfsRec(int source) { 
	
	for(pi ady : tree [source] )  
		if ( parent[ady.second] == -1)  {

			parent[ady.second] = source; 
			cost[ady.second] = min(cost[source], ady.first) ; 

			dfsRec(ady.second); 
		}

}

void kruskal() { 
	pii help ; 


	while ( !myQ.empty() ) { 
		help = myQ.top(); 

		if( find(help.second.first) != find(help.second.second) ) {// create tree whilo joinin different sets guided by PQ

			onion ( help.second.first, help.second.second ) ; 

			tree[help.second.first].push_back( { help.first, help.second.second} ) ; 
			tree[help.second.second].push_back( { help.first, help.second.first} ) ;	

		}

		myQ.pop(); 
	}
}

int main() { 
	int t,n,m,u,v, k; 
	long long w; 

	
	scanf("%d",&t); 

	k = t; 

	while ( k-- ) { 
		scanf("%d %d", &n, &m); 

		for(int i=0; i<n; i++) { 	// init
			rnk[i] = 0; group[i] = i; 
			parent[i] = -1; cost[i] = MAXINT; closed[i] = false; 

		}

		for(int i=0; i<m ;i++) { 
			scanf("%d %d %lld",&u,&v,&w); 
			myQ.push( { w, {u-1, v-1} }); 
		}


		// algorithm goes here

		if ( m < n - 1)
			resp[t-k-1] = -1; 
		else{
			kruskal(); 

			parent[0] = 0;   
			bfs(0); 

			resp[t-k-1] = cost[n-1];

			for(int i=0 ;i<n; i++) tree[i].clear(); // clean
		}
				

		//
			
	}

	
	for(int i=0 ; i<t; i++) printf("%lld\n",resp[i]); 
}

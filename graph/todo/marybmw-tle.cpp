#include<stdio.h> 
#include<iostream> 
#include<queue> 
#include<vector> 
#include<set> 

#define MAXT 5
#define MAXS 50000

using namespace std; 

typedef pair<long long, int > pi; 
typedef pair<long long, pair<int, int> > pii; 

vector< pi > *graph = new vector<pi> [MAXS]; 
set<int> cut; 

long long cost[MAXS];
int parent[MAXS]; 

long long resp[MAXT]; 


void prim(int source, int size) { 
	priority_queue< pii, vector<pii>, greater<pii> > myQ; 
	int cnt = 0; 
	pii help ; 
	cost[source] = 0; 	

	myQ.push( { 0, {source, source } } ); 

	while ( !myQ.empty() && cnt != size) { 
		help = myQ.top(); 

		cut.insert( help.second.first ) ;		//insert child into cut 
		parent[help.second.first] = help.second.second; 
		cost[help.second.first] = help.first; 		// < weight, child, parent >

		myQ.pop(); 
		
		for(pi ady : graph[help.second.first] )  
			if ( cut.find( ady.second ) == cut.end() )   // add edges with extremes not in cut to PQ
				myQ.push( { ady.first, {ady.second, help.second.first} } ); 	
			
		cnt+=1; 
	}

	cut.clear(); 
}



int main () { 
	int t, n, m, u, v, k; 
	long long w; 

	scanf("%d",&t); 

	k=t; 

	while (k--) { 
		scanf("%d %d", &n, &m); 

		for(int i=0; i<n; i++) { cost[i] = 0; parent[i] = i; } //init

		for(int i=0; i<m; i++) { 
			scanf("%d %d %lld",&u,&v,&w); 
			graph[u-1].push_back( {w,v-1} ); 	
		}

		// algorithm goes here

		if ( m < n-1) 
			resp[t-k-1] = -1; 
		else {
			prim(0, n); 	

			int dum = n-1;
			long long out; 

			cout<<"parent\n"; 
			for(int i=0; i<n; i++) printf("%d ",parent[i]); 
			cout<<endl; 
			cout<<"cost\n"; 
			for(int i=0 ;i<n; i++) printf("%lld ",cost[i]); 
			cout<<endl; 

			while ( dum != 0 ) {  
				out = min ( out, cost[dum] ) ;
				dum = parent[dum]; 
			}
			resp[t-k-1] = out; 
		}
		//

		for(int i=0; i<n; i++) graph[i].clear(); //clear
	}

	for(int i=0; i<t; i++) printf("%lld\n",resp[i]); 
}

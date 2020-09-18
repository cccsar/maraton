#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <queue> 

#define MAXT 5
#define MAXS 50000

using namespace std; 

typedef pair<long long, pair<int, int> > pli; 


vector< pair<long long, int> > *graph = new vector<pair<long long, int > >[MAXS]; 
priority_queue<pli, vector<pli>, greater<pli> > myQ; 
int resp[MAXT]; 

int rnk[MAXS], group[MAXS], parent[MAXS]; 

int find (int el ) {
	int dum = el ;

	while ( dum != group[dum] ) 
		dum = group[dum]; 

	if ( el != dum )
		group[el] = dum; 

	return dum; 
}

void onion (int u, int v) {
	int x = find(u), y=find(v);

	if ( x != y ) { 
		if (rnk[x] >= rnk[y]){
			group[y] = x; 
			if ( rnk[x] == rnk[y] )
				rnk[x] += 1;
		}	
		else
			parent[x] = y;
	}
} 

int main() { 
	int n,m,u,v ; 
	long long w; 

	scanf("%d %d",&n, &m); 

	for(int i=0; i<m;i++) { 
		scanf("%d %d %lld",&u, &v, &w);
		myQ.push( {w, {u-1, v-1} } ); 
		graph[u-1].push_back( {w, v-1} ) ; 
		graph[v-1].push_back( {w, u-1} ); 
	}

	// algorithm goes here
	
	int cnt = 0; 
	while ( cnt != n-1) { 
		u = myQ.top().second.first; v = myQ.top().second.second; 

		if (find(u) != find (v) )  
			onion(u, v); 
		cnt+=1; 
	}
	
	//
}



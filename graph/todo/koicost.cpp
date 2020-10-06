#include<stdio.h> 
#include <iostream> 
#include <vector> 
#include <queue> 

#define MAXS 100000

using namespace std; 

int rnk[MAXS], cRnk[MAXS], parent[MAXS], cParent[MAXS]; 
priority_queue< pair<long long, pair<int, int> > > myQ; 

int find(int e, int parent[]) {
	int dum = e; 

	while ( dum != parent[dum] ) 
		dum = parent[dum]; 

	if ( dum != e )
		parent[e]= dum; 

	return dum; 
} 


bool onion (int u, int v, int parent[], int rnk[] ) {  
	int x = find (u, parent), y = find (v, parent) ;

	if ( x != y ) { 
		if( rnk[x] >= rnk[y]) {
			parent[y] = x; 
			if(rnk[x] == rnk[y])
				rnk[x]+=1;
		}
		else
			parent[x] = y;

		return false;
	}
	else 
		return true; 
}

long long cost(int u, int v) { 
	vector< pair<long long, pair<int, int> > > help ; 
	long long tot =0; 

	if ( find (u,parent) == find (v,parent) ) { 

		while (true) { 
			help.push_back( myQ.top() ); 
			myQ.pop(); 
			onion( help[ help.size() - 1].second.first, help[help.size() -1].second.second, cParent,cRnk ) ;

			if ( find(u, cParent) == find(v,cParent) ) 
				break ;
			else 
				tot += help[ help.size() -1].first; 
		}

		for(pair<long long, pair<int, int> >  el : help) {  // restore MaxPQ and small arrays for DSU
			myQ.push( el ) ;
			cParent[el.second.first] = el.second.first; 
			cRnk[el.second.first] = 0; 
			cParent[el.second.second] = el.second.second; 
			cRnk[el.second.second] = 0 ;
		}
		// unsure of how much this costs

		return tot; 
	}
	else
		return 0; 
}

int main () {
	int n, m, u, v; 

	long long w, acc = 0, resp = 0; 

	scanf("%d %d",&n, &m) ;

	for(int i=0; i<n; i++) { rnk[i] = cRnk[i] = 0 ; parent[i] = cParent[i] = i; } //init

	for(int i=0; i<m; i++) { 
		scanf("%d %d %lld", &u, &v, &w) ; 

		acc += w; 			// accumulate cost of all edges
		onion(u-1,v-1,parent,rnk); 	// have separate sets for al connected graphs vertix
		myQ.push ( {w,{u-1,v-1}} ); 	// use a maxPQ since algorithm is based on MAXst
	}

	// algorithm goes here
	
	for(int i=0; i<n-1; i++)  
		for(int j=i+1; j<n; j++)  
			resp += acc - cost(i,j); // accumulate cost of i,j
	//
	
	printf("%lld\n",resp%1000000000); 
}

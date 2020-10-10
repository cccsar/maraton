#include<stdio.h> 
#include<iostream> 
#include<vector> 

#define MAXN 2*200000

using namespace std; 

bool color[MAXN], vtd[MAXN];
vector<int> * tree = new vector<int> [MAXN]; 

int dfsRec(int source, int *mx) { //NOT A SOLUTION
	int cs = color[source]? 1 : -1, curr; 

	for(int ady : tree[source]) { 
		vtd[ady] = true; 
		curr = dfsRec(ady, mx); 
		*mx = max (*mx, curr ); // check for maximum at each sub-branch termination 

		cs += curr >= 0 ? curr : 0 ;// accumulate cost of branches of tree
	}


	if ( cs > 0 ) 
		return cs ;
	return 0; 
} 

int main() { 
	int n, u, v, e ;

	cin >> n; 
	
	for(int i=0; i<n; i++) { 
		cin >> e; 
		color[i] = e? true: false; 
	}	

	for(int i=0 ;i<n-1;  i++) { 
		cin >> u >> v;
		tree[u-1].push_back( v-1 ); 
		tree[v-1].push_back( u-1 ); 
	}

	int mx = -1; 

	dfsRec(0, &mx); 

	cout<<mx<<'\n'; 

}

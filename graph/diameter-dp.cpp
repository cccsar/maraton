#include<stdio.h> 
#include<vector> 

using namespace std; 

typedef vector<int> vi; 

const int MAXN = 0x7ffffff ;

vi *graph = new vi [MAXN] ; 
vector<bool> vtd (false, MAXN); 
vi diam (-1,MAXN) ; 

int dfs_rec(int s) { 

	int mx = 0; 
	for(const auto ady : graph[s] ) { 
		if ( !vtd[ady] ) { 
			vtd[ady] = true; 
			mx = max ( mx, dfs_rec( ady ) ) ; 
		}
	}


	return diam[s] = 1 + mx ;
} // computes diameter of a tree

int main() { 
	int n,m,u,v; 

	scanf("%d %d",&n, &m); 

	for(int i=0; i<m ;i++) { 

		scanf("%d %d",&u, &v); 
		graph[u].push_back(v); 
		graph[v].push_back(u); 
	}
	
	vtd[0] = true; 
	printf("%d\n",dfs_rec(0));
}

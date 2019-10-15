#include <iostream> 
#include <stdio.h>
#include <vector> 

using namespace std; 

#define FOR(n) for(int i=0; i<n; i++) 
#define ROF(n) for(int i=n; i>0; i--) 
#define rint(c) scanf("%d",&c)
#define rints(c,cc) scanf("%d %d",&c,&cc)

//type for adyacency list
typedef vector< vector<int> > adyl ;


#define MAX_NODES 30000

adyl my_adyl(MAX_NODES);
int parent[MAX_NODES];

/*	Recovery of dfs paths	*/
void path_print(int n) { 
	int d; 

	FOR(n) { 
		d = i; 
		while (d != parent[d] && parent[d] != -1) { 
			cout<<d<<" "; 
			d = parent[d]; 	
		}
		
		if(parent[d]!=-1 || paren[d]==d)
			cout<<parent[d]<<endl;
	}
}

vector<int> getAdyacents(int current) {

	return my_adyl[current]; 
}


void dfs_r(int current) { 
	
	vector<int> ady;
	int d;

	ady = getAdyacents(current); 

	FOR(ady.size()) {
		
		d = ady[i]; 
		if( parent[d] == -1 ) 
		{ 
			parent[d] = current; 
			dfs_r(d); 
		}
	}
		
}

int main() 
{

	return 0; 
}

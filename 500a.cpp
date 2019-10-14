
#include <iostream> 
#include <vector> 
#include <list> 
#include <utility>

using namespace std; 

#define FOR(n) for(int i=0; i<n; i++) 
#define ROF(n) for(int i=n; i>0; i--) 
#define rint(c) scanf("%d",&c)
#define rints(c,cc) scanf("%d %d",&c,&cc)

typedef vector< list<int> > adyl ;


#define MAX_NODES 30000
#define MAX_ADY 100

adyl my_adyl(MAX_NODES,{-1});
int parent[MAX_NODES];



list<int> getAdyacents(int current) {

	return my_adyl[current]; 
}

void dfs_r(int current) { 
	
	list<int> ady = getAdyacents(current); 
	int d;


	FOR(ady.size()) {
		
		d = ady.front(); //### 
		if( parent[d] != -1 ) 
		{ 
			parent[d] = current; 
			dfs_r(d); 
		}
		ady.pop_front(); //###
	}
		
}

int main() 
{
	int nc, tc; 

	FOR(nc) 
		parent[i] = -1; 

	int x,y; 
	FOR(tc) { 
		rints(x,y); 
		my_adyl[x].push_back[y]; 
	}

	dfs_r(1); 

	//rints(nc,tc); 	

	//int x,y; 
	//FOR(nc) { 
	//	rints(x,y); 
	//	my_adyl[x].push_back[y]; 
	//}



	return 0; 
}

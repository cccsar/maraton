#include <iostream> 
#include <stdio.h>
#include <vector> 

using namespace std; 

#define FOR(n) for(int i=0; i<n; i++) 
#define ROF(n) for(int i=n; i>0; i--) 
#define BFOR(l,u) for(int i=l; i<u; i++) 
#define rint(c) scanf("%d",&c)
#define rints(c,cc) scanf("%d %d",&c,&cc)

typedef vector< vector<int> > adyl ;


#define MAX_NODES 30001

adyl my_adyl(MAX_NODES);
int parent[MAX_NODES];


vector<int> getAdyacents(int current) {

	return my_adyl[current]; 
}


void dfsRec(int current) { 
	
	vector<int> ady;
	int d;

	ady = getAdyacents(current); 

	FOR(ady.size()) {
		
		d = ady[i]; 
		if( parent[d] == -1 ) 
		{ 
			parent[d] = current; 
			dfsRec(d); 
		}
	}
		
}

int main() 
{
	int nc, tc; 
	rints(nc,tc);


	FOR(nc) 
		parent[i] = -1; 
	parent[0] = 0;

	int rng; 
	FOR(nc-1) { 
		rint(rng);
		my_adyl[i].push_back(i+rng); 
	}


	dfsRec(0);
	BFOR(1,nc)
		dfsRec(i);


	int d = tc-1;
	while(d!=parent[d] && d!=-1)  
		d = parent[d];

	(d == 0)? printf("YES\n"): printf("NO\n");


	return 0; 
}

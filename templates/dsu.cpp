#include<iostream> 

#define MAXS 100000
#define MAXINT 0x7fffffff

using namespace std; 

int rnk[MAXS], parent[MAXS]; 

int find(int el) { 
	int dum = el ;

	while ( parent[dum] != dum) 
		dum =parent[dum];

	parent[el] = dum; 

	return dum; 

}

void find(int u, int v) { 
	int x = find(u), y = find(v); 

	if (x != y ) {
		if (rnk[x] >= rnk[y]){
			parent[y] = x; 
			if (rnk[x] == rnk[y] )
				rnk[x] +=1; 
		}
		else 
			parent[x] = y;
	}
}

#include<stdio.h> 
#include<vector> 
#include<queue> 

#define MAXS 100000
#define MAXINT 0x7fffffff

using namespace std; 

typedef pair<int, int> pi; 
typedef pair<int, pi> pii; 

priority_queue<pii> myQ; 

int parent[MAXS], rnk[MAXS] ;

int find(int el ) { 
	int dum = el; 

	while ( parent[dum] != dum) 
		dum = parent[dum] ;

	parent[el] = dum; 

	return dum; 
}

void onion(int u, int v) { 
	int x = find(u), y = find(v); 

	if (x != y){
		if (rnk[x] >= rnk[y]) {
			parent[y] = y; 
			
			if (rnk[x] == rnk[y])
				rnk[x]+=1; 
		}
		else 
			parent[x] = y; 
	}	
}

void prim(int size) { // the queue is assumed to have all edges with negatives weights (for propper ordrering)
	pii curr; 
	int cnt = 0; 

	while ( !myQ.empty() && cnt != size -1  ) { 
		curr = myQ.top(); 
		myQ.pop(); 

		if (find(curr.second.first) != find(curr.second.second)) { // i didn's use to check this
			onion(curr.second.first, curr.second.second); 
			cnt +=1; 
		}	
	}	
}

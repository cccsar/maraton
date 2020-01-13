#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<deque>
#include<utility>
#include<climits> 
#include<string.h> 

#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",s)
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 

#define UB 5 
#define MAXSS 10
	
using namespace std; 

int parent[100000];
int rank[100000];
int resp[10]; 

int myFind(int e) { 
	int dummie;

	dummie = e; 

	while( parent[dummie] != -1) 
		dummie = parent[dummie] ; 

	if ( e != dummie ) 
		parent[e] = dummie; 

	return dummie; 
}

void myUnion (int u, int v,int *nsets) {
	int x, y; 

	x = myFind(u); 
	y = myFind(v); 

	if ( x != y ) {

		if ( rank[x] >= rank[y] ) {
			parent[y] = x; 
			if (rank[x] == rank[y])
				rank[x]+=1 ;
		}
		else 
			parent[x] = y; 

		*nsets -= 1;
	}
}

int main() 
{
	int i_, j_, t, n, m, u, v, nsets; 

	memset(parent, -1, sizeof(int) * 100000); 
	memset(rank, 0, sizeof(int) * 100000); 

	ri(t); 
	for(i_=0; i_<t; i_++) { 	
		rii(n, m); 	
		nsets = n; 

		for(j_=0; j_<m ; j_++) {
			rii(u , v); 	
			myUnion(u, v, &nsets); 
		}

		resp[i_] = nsets; 
		
		for(j_=0; j_<n ; j_++) 
			parent[j_] = -1; 	
	}

	for(i_=0; i_<t ; i_++) 
		cout<<resp[i_]<<endl ;	

	return 0 ;
}

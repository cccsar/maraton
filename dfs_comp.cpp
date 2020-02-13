#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<set> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 

using namespace std; 

#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",&s)

typedef vector< int > vi; 
typedef vector< pair<int, int> >  vii; 
typedef vector< int, pair<int, int> >viii; 
typedef pair <int, int> pi; 
typedef pair <int, pair<int, int> > pii; 
typedef vector< vi > adl; 
typedef vector< vii > wadl; 

#define MAXSIZE 1000
	
int parents[MAXSIZE]; 
int rk[MAXSIZE] ;

void adl_insert(adl &graph, int u, int v) { 
	graph[u].push_back(v); 
	graph[v].push_back(u); 
};

//anadir firma de padres en algun momento
void dfs_rec(adl &graph, int r) { 
	int i_; 
	
	for (i_=0 ; i_<graph[r].size() ; i_++) { 

		if ( parents[ graph[r][i_] ] == -1) { 
			parents[ graph[r][i_] ] = r; 
			dfs_rec(graph, graph[r][i_]); 
		}
	}
};

int myFind(int e, int r) { 
	int dum; 

	dum = e; 

	while ( dum != r ) {
		dum = parents[dum] ;
	}

	if ( dum != e) 
		parents[dum] = e ;

	return dum;
};

void myUnion(int x, int y, int r) { 
	int px, py;

	px = myFind(x, r); 
	py = myFind(y, r); 

	if (px != py) { 
		if (rk[px] >= rk[py] ) {
			parents[py] = px ;
			if(rk[px] == rk[py])  
				rk[px] += 1; 
		}
		else { 
			parents[px] = py; 
		}
	}

};


int main() {
	int i_, j_, u, v, n, m ;
	adl list;
	list.reserve(MAXSIZE);

	rii(n, m);

	for (i_=0 ; i_<n ; i_++)  {
		parents[i_] = -1; 
		rk[i_] = 0;
	}
	parents[0] = 0 ;


	for (i_=0 ; i_<m ; i_++) { 
		rii(u, v); 
		adl_insert(list, u, v); 
	}
	
	dfs_rec(list, 0); 

	for (i_=0 ; i_<n ; i_++) 
		myFind(i_, 0); 
	

	for (i_=0 ; i_<n ; i_++)  
		cout<<parents[i_]<<" "; 
	cout<<endl; 	

	return 0; 
}

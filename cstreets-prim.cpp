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
	
const int MAXS = 1000;
const int MAXT = 100;

bool visited[MAXS] ;
int resp[MAXS] ;


void addWEdge(vii graph[], int u, int v, int w ) { 
	pi perico = { w, v }; 

	graph[u].push_back( perico ) ;

	perico.second = u; 

	graph[v].push_back( perico ) ; 
}


int myPrim(vii graph[], int root, int size) { 
	int mincost; 
	priority_queue< pi, vector<pi>, greater<pi> > my_pq; 
	pi dummie; 

	my_pq.push( {0, root} ); 

	mincost = 0; 
	
	while ( !my_pq.empty() ) {
		dummie = my_pq.top(); 
	       	my_pq.pop(); 
		
		if ( !visited[ dummie.second ] ) { 	//if not visisted check successors

			visited[ dummie.second ] = true;  
			mincost += dummie.first ; 

			for(pi k : graph[dummie.second]) { 
				if (!visited[k.second])  
					my_pq.push( k ); 
			}
		}

	}

	return mincost; 
}


int main() 
{
	int t, n, m, a, b, c, i_, j_, p; 
	vii *graph = new vii[MAXS]; 

	for(i_=0; i_<MAXS ; i_++) 
		visited[i_] = false; 	


	ri(t); 

	for (i_=0 ; i_<t ; i_++) { 

		ri(p); 
		rii(n,m); 
	
		for(j_=0; j_<m ; j_++) {
			riii(a,b,c); 	
			addWEdge(graph, a-1, b-1, c); 
		}

		resp[i_] = p*myPrim(graph, 0, n); 


		for (j_=0 ; j_<n ; j_++)  {
			visited[i_] = false; 
			graph[j_].clear(); 
		}
	}


	for (i_=0 ; i_<t ; i_++)  
		cout<<resp[i_]<<endl;

	return 0; 
}

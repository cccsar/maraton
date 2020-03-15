#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<vector>
#include<queue>
#include<utility>

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

const int MAXINT = 2147483647;

	
const int MAXS = 1000000;
const int MAXTESTS = 100; 

int resp[MAXTESTS]; 


void invGraph(vii inv_graph[], vii dir_graph[], int size ) { 
	int i_;

	for(i_=0; i_<size ; i_++) {
		for(pi k : dir_graph[i_] ) 
			inv_graph[ k.second ].push_back( { k.first, i_ } ) ; 	
	}
}


void myDijkstra(vii graph[], int cost[], const int source) { 
	priority_queue< pi, vector<pi> , greater<pi> > best; 
	pi perico; 

	best.push( {0, source} ) ; 
	cost[source] = 0; 

	while( !best.empty() ) { 
		perico = best.top(); 
		best.pop(); 

		for(pi suc: graph[ perico.second ] ) { 

			if ( cost[ suc.second ] > suc.first + cost[ perico.second ] ) { 

				cost[ suc.second ] = suc.first + cost[ perico.second ] ;
				best.push( suc ) ; 
			}
		}
	}

}

int main() 
{
	int t, s, l, o, d, p , i_, j_, acum; 
	int cost[MAXS], inv_cost[MAXS]; 
	vii *digraph, *inv_graph;
	
	digraph = new vii[MAXS]; 
	inv_graph = new vii[MAXS]; 

	for(i_=0; i_<MAXS ; i_++) 
		cost[i_] = inv_cost[i_] = MAXINT; 

	acum = 0 ;
	ri(t); 

	for(i_=0; i_<t ; i_++) {
		rii(s, l); 

		for(j_=0; j_<l ; j_++) {
			riii(o, d, p); 	
			digraph[o-1].push_back( { p, d-1} ) ;
		}		


		invGraph(inv_graph, digraph, s); 

		myDijkstra(digraph, cost, 0); 
		myDijkstra(inv_graph, inv_cost, 0); 

		for(j_=0; j_<s ; j_++) 
			acum += cost[j_] + inv_cost[j_]; 	

		resp[i_] = acum; 
		

		for(j_=0; j_<s ; j_++) {
			cost[j_] = inv_cost[j_] =  MAXINT; 
			digraph[j_].clear(); 
			inv_graph[j_].clear(); 		
		}	

		acum = 0; 
	}

	for(i_=0; i_<t ; i_++) 
		cout<<resp[i_]<<endl;	


	return 0; 
}

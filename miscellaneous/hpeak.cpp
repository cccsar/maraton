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

const int MAXINT = 2147483647;


const int MAXS = 10000;
const int MAXT = 500; 

bool excluded[MAXS][MAXS];
int resp[MAXT]; 

void dijkstra(vii digraph[], int cost[], const int source) { 
	priority_queue< pi, vector<pi>, greater<pi> > npi; 
	pi dum; 
	
	cost[ source ] = 0; 	
	npi.push( {0, source} ); 

	while( !npi.empty() ) { 
		dum = npi.top(); 
		npi.pop(); 

		for(pi uwu: digraph[ dum.second ] ){ 
			if ( cost[ dum.second ] + uwu.first < cost[ uwu.second ] ) { 
				cost[ uwu.second ] = cost[ dum.second ] + uwu.first  ;
				npi.push( uwu ); 
			}
		}
		
	}	
}


int main() 
{
	int p, t, u, v, l, i_, acum, ct; 
	int cost_e[MAXS], cost_hp[MAXS]; 
	vii control; 

	vii *graph = new vii[MAXS]; 

	ct = 0;

	for(i_=0; i_<MAXS ; i_++) 
		cost_e[i_] = cost_hp[i_] = MAXINT; 	

	while( scanf("%d %d", &p, &t) != EOF) { 
		acum = 0;

		for(i_=0; i_<t ; i_++) {
			riii(u, v, l); 

			graph[u].push_back( {l, v} ); 
			if( u != v )
				graph[v].push_back( {l, u} ); 
		}		

		dijkstra(graph, cost_hp, p-1); 
		dijkstra(graph, cost_e, 0); 

		for(i_=0; i_<p ; i_++) {
			for(pi nein : graph[i_]) { 
				if ( cost_e[i_] + nein.first + cost_hp[ nein.second ] == cost_e[p-1] 
						&& !excluded[nein.second][i_] ){
					acum += nein.first; 
					excluded[nein.second][i_ ] = true; 	
					control.push_back( {i_, nein.second} ) ;
				}
			}				
		}	
	
		resp[ct] = 2*acum; 

		for(i_=0; i_<p ; i_++) {
			graph[i_].clear(); 
			cost_e[i_] = cost_hp[i_] = MAXINT; 
			excluded[ control[i_].first ][ control[i_].second ] = false; 
		}	
		
		control.clear(); 
		ct += 1; 
	}

	
	for(i_=0; i_<ct ; i_++) 
		cout<<resp[i_]<<endl; 		

	return 0; 
}

#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<vector>
#include<queue>
#include<utility>
#include<climits> 
#include <string.h>
#include<unordered_map> 


#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",s); 
#define pi pair<int, int> 
#define pii pair<int, pair<int, int> >
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define wadl vector< vii >

using namespace std; 

wadl conections; 
unordered_map<string, int> cities_n; 

priority_queue< pii , vector< pii >, greater< pii > > weights ;
int resp[10000];

int out[1000]; 

void myDijkstra(int r) {
	pii dum, help ; 

	resp[r] = 0 ;
	dum.first = 0; 
	dum.second.first = r; 
	dum.second.second = r; 

	weights.push( dum ) ; 

	while( !weights.empty() ) { 
		dum = weights.top(); 
		weights.pop(); 

		//check if popped weigth + accum. path is smaller than shortest path maintained
		if( resp[ dum.second.second ] + dum.first < resp[ dum.second.first ] ) 
			resp[ dum.second.first ] = resp[ dum.second.second ] + dum.first ;

		for( pi it : conections[ dum.second.first ] ) { 

			//Check if current adyacent wasn't already included in resp 
			if ( resp[ it.second ] == INT_MAX ) {
				help.first = it.first; 
				help.second.first = it.second;
				help.second.second = dum.second.first; 

				weights.push( help ) ; 
			}
		}

	}

}

void wadlInsert(int u, int w, int v) 
{
	pair<int, int> help ;
	help.first = w;
	help.second = v; 

	conections[u].push_back(help); 
}

int main() 
{
	int i_, j_, s_, n_, p_, v_, k_, cost, r_, acum ; 
	string c_name, o_c_name; 

	conections.reserve(10000); 

	for(i_=0; i_<10000 ; i_++) 
		resp[i_] = INT_MAX ; 	
	acum = 0 ;
	

	ri(s_); 

	for(i_=0; i_<s_ ; i_++) {

		ri(n_); 
		for(j_=0; j_<n_ ; j_++) {

			//leo info para un_map 
			cin>>c_name; 	

			cities_n[c_name] = j_; 	//aqui se llena la thash de nombres 

			ri(p_); 
			for(k_=0; k_<p_ ; k_++) {	//aqui se llena el grafo de la ciudad

				rii(v_, cost); 
				wadlInsert(j_, cost, v_ - 1); 	
			}	

		}	


		ri(r_); 
		for(j_=0; j_<r_ ; j_++) {
			cin>>c_name>>o_c_name; 

			myDijkstra( cities_n[c_name] );

			out[ acum + j_ ] = resp[ cities_n[o_c_name] ]; 
			
			for(k_=0; k_<n_ ; k_++) 
				resp[k_] = INT_MAX; 	

		}	
		acum += r_;

		//cleaning memo 
		for(j_=0; j_<n_ ; j_++) 
			conections[j_].clear(); 		
		cities_n.clear(); 
		
		
	}

	for(i_=0; i_<acum ; i_++) 
		cout<<out[i_]<<endl; 	

	return 0; 
}

#include<stdio.h> 
#include<vector> 
#include <utility> 
#include<unordered_map> 
#include<iostream> 
#include<string> 

#define MAXS 30 
#define MAXW 100
#define BIG 10000

using namespace std; 

vector < pair<float, int > > *graph = new vector< pair<float, int> > [MAXS] ; 
unordered_map<string, int > mp ; 

// bellman modified
float cost[MAXS] ; 

bool resp[BIG]; 


bool modifBellman (int source, int size) { // <>, *> based bellman that detects "negative costs cycles "
	bool change = true; 
	int cnt = 0; 

	cost [ source ] = 1; // identity of * (?)  

	while ( change && cnt != size ) { 

		for(int i=0 ;i<size; i++) 
			for( pair<float, int> ady : graph[i] )  
				if ( cost[i] * ady.first > cost[ady.second ]) { 
					cost[ady.second ] = cost[i] * ady.first ; 
					change = true; 
				}
		cnt+=1; 
	}


	for(int i=0 ;i<size; i++) 
		for( pair<float, int> ady : graph[i] ) { 
			if ( cost[i] * ady.first > cost [ ady.second ] ) 
				return true; 
		}

	return false; 
}

int main(){ 
	int n, m , cnt =0 ; 
	string u, v, wd; 
	float w; 


	while ( scanf("%d",&n) && n != 0 ) { 

		for(int i=0; i<n; i++) cost[i] = -1; //init
		

		for (int i=0; i<n; i++) { cin>> wd; mp[wd] = i ; } 

		scanf("%d",&m); 


		for(int i=0; i<m; i++) { 
			cin>>u>>w>>v;   
			graph[ mp[u] ].push_back ( { w, mp[v] } ) ; 	
		}

		// algorithm 

		resp[cnt] = modifBellman ( 0 , n ) ; 

		//
	
		cnt+=1; 

		for(int i=0; i<n; i++) graph[i].clear();   // cleaning
		mp.clear() ;
	}

	for(int i=0 ;i<cnt; i++) printf("Case %d: %s\n", i+1, (resp[i])? "Yes": "No" ) ; 
}	

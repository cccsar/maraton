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


const int MAXS = 200; 
const int MAXT = 10;

int resp[MAXT]; 

void getSucc(vii &succ, int x, int y, int width, int height ) { 
	if ( x > 0)
		succ.push_back( {x-1, y} ); 
	if ( x <= width)
		succ.push_back( {x+1, y} ); 
	if ( y > 0)
		succ.push_back( {x, y-1} ); 
	if ( y <= height )
		succ.push_back( {x, y+1} ); 
}

void bfsCost(int cost[][MAXS+1], char plot[][MAXS+1], int i, int j, int width, int height) { 
	queue<pi> kiu; 
	vii succ; 
	pi help, uwu;

	kiu.push( {i, j} ) ; 
	cost[ i ][ j ] = 0; 

	while( !kiu.empty() ) { 
		help = kiu.front(); 
		kiu.pop(); 
		
		getSucc(succ, help.first, help.second, width, height); 
		
		while ( !succ.empty() ) { 
			uwu = succ.back(); 
			succ.pop_back(); 

			if ( cost[ uwu.first ][ uwu.second ] == MAXINT 
					&& plot[uwu.first][uwu.second] != '#'){
				cost[ uwu.first ][ uwu.second ] = cost[help.first][help.second] + 1;
				kiu.push( uwu );
			}
		}
			
	}
}


int main() 
{
	int t, n, m, i_, j_, k_; 
	int cost_a[MAXS+1][MAXS+1], cost_b[MAXS+1][MAXS+1], cost_c[MAXS+1][MAXS+1];	
	char graph[MAXS+1][MAXS+1], word[MAXS];
	vii begins; 


	for(i_=0; i_<=MAXS; i_++) {		//init structures
		for(j_=0; j_<=MAXS; j_++)  {
			graph[i_][j_] = '.';
			cost_a[i_][j_] = cost_b[i_][j_] = cost_c[i_][j_] = MAXINT;  
		}
	}

	ri(t); 

	for(i_=0; i_<t ; i_++) {
		rii(n,m); 
		for(j_=1; j_<=n ; j_++) {
			scanf("%s",word); 
			for(k_=1; k_<=m ; k_++) {
				graph[j_][k_] = word[k_-1]; 
				
				//if not a '.' or a '#', consider it a begin
				if( graph[j_][k_] > '0' && graph[j_][k_] < '4' )
					begins.push_back( {j_, k_} ); 
			}
		}	


		bfsCost(cost_a, graph, begins[0].first, begins[0].second, n, m); 
		bfsCost(cost_b, graph, begins[1].first, begins[1].second, n, m); 
		bfsCost(cost_c, graph, begins[2].first, begins[2].second, n, m); 
		
		int help, less = MAXINT; 
		for(j_=0; j_<n+1 ; j_++) {
			for(k_=0; k_<m+1 ; k_++) {
				help = max( cost_a[j_][k_], max(cost_b[j_][k_], cost_c[j_][k_]) ); 

				if ( graph[j_][k_] != '#' && less > help) 
					less = help ;
			}
		}	
		

		resp[i_] = less; 

		for(j_=0; j_<=n+1 ; j_++) { //clearing memory
			for(k_=0; k_<=m+1 ; k_++) {
				graph[j_][k_] = '.';
				cost_a[j_][k_] = cost_b[j_][k_] = cost_c[j_][k_] = MAXINT;  
			}
		}	

		begins.clear(); 

	}	

	for(i_=0; i_<t ; i_++) 
		cout<<resp[i_]<<endl; 	

	return 0; 
}

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

const int MAXINT = 0x7fffffff;


const int MAXS = 202; 
const int MAXT = 11;

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

void bfsCost(int cost[][MAXS], char plot[][MAXS], int i, int j, int width, int height) { 
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
	int t, n, m; 
	int cost_a[MAXS][MAXS], cost_b[MAXS][MAXS], cost_c[MAXS][MAXS];	
	char graph[MAXS][MAXS], word[MAXS];
	vii begins; 


	for(int i=0; i<MAXS; i++) {		//init 
		for(int j=0; j<MAXS; j++)  {
			graph[i][j] = '.';
			cost_a[i][j] = cost_b[i][j] = cost_c[i][j] = MAXINT;  
		}
	}

	ri(t); 

	for(int i=0; i<t ; i++) {

		rii(n,m); 

		for(int j=1; j<=n ; j++) {
			scanf("%s",word); 

			for(int k=1; k<=m ; k++) {
				graph[j][k] = word[k-1]; 
				
				//if not a '.' or a '#', consider it a begin
				if( graph[j][k] > '0' && graph[j][k] < '4' )
					begins.push_back( {j, k} ); 
			}
		}	

		// algorithm 

		bfsCost(cost_a, graph, begins[0].first, begins[0].second, n, m); 
		bfsCost(cost_b, graph, begins[1].first, begins[1].second, n, m); 
		bfsCost(cost_c, graph, begins[2].first, begins[2].second, n, m); 
		
		int help, less = MAXINT; 
		for(int j=0; j<=n+1 ; j++) {
			for(int k=0; k<=m+1 ; k++) {
				help = max( cost_a[j][k], max(cost_b[j][k], cost_c[j][k]) ); 

				if ( graph[j][k] != '#' && help < less) 
					less = help ;
			}
		}	
		
		//

		resp[i] = less; 

		for(int j=0; j<=n+1 ; j++) { //clean
			for(int k=0; k<=m+1 ; k++) {
				graph[j][k] = '.';
				cost_a[j][k] = cost_b[j][k] = cost_c[j][k] = MAXINT;  
			}
		}	

		begins.clear(); 

	}	

	for(int i=0; i<t ; i++) cout<<resp[i]<<endl; 	

	return 0; 
}

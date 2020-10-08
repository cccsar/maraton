#include<stdio.h> 
#include<iostream> 
#include<utility> 
#include<vector> 
#include<queue>
#include<set> 

#define MAXT 1000
#define MAXN 182
#define MAXINT 0x7fffffff

using namespace std; 

typedef pair<int, int> pi ; 
typedef vector<pi> vi; 

set<pi> cands; 
pi sizes[MAXN]; 

short cost[MAXN][MAXN]; 
bool inp[MAXN][MAXN]; 

short resp[MAXT][MAXN][MAXN]; 

void adyacents(queue<pi> &ady, pi &coord, int width, int height) {	// guarantees ady aren't visited
	if ( coord.first > 0 ) 
		ady.push( {coord.first - 1, coord.second} );
	if ( coord.first < width ) 
		ady.push( {coord.first + 1, coord.second} ); 
	if ( coord.second > 0) 
		ady.push( {coord.first, coord.second - 1} ); 
	if ( coord.second < height) 
		ady.push( {coord.first, coord.second + 1} ); 
} 


void bfsRestricted(int x, int y, int width, int height) {
	queue<pi> myQ, ady; 
	pi dum, curr; 

	myQ.push( {x, y} ); 

	cost[x][y] = 0 ;

	while ( !myQ.empty() ) { 
		dum = myQ.front(); 
		myQ.pop(); 

		adyacents(ady, dum, width, height); 

		while ( !ady.empty() ) { 
			curr = ady.front(); 
			ady.pop(); 

			if ( cost[dum.first][dum.second] + 1 < cost[curr.first][curr.second]  ) { 
				if ( inp[curr.first][curr.second] )  {
					if ( inp[dum.first][dum.second] ) { 	// consec sources
						cost[curr.first][curr.second] = 0; 
						myQ.push( { curr.first, curr.second } ); 
					}
					else	   				// non consec
						cands.insert( { curr.first, curr.second } ) ; 
				}
				else { 
					// regular node, relax 
					cost[curr.first][curr.second] = cost[dum.first][dum.second] + 1 ;
					myQ.push( { curr.first, curr.second } ); 
				}
			}
		}
	}
} 

int main() {
	int t, n ,m , k ; 
	char word[MAXN]; 

	scanf("%d",&t); 

	k = t; 

	pi fst; 
	bool chk = false; 
	while ( k -- ) { 
		scanf("%d %d",&n, &m); 

		for(int i=0 ;i<n; i++)  //init 
			for(int j=0; j<m ;j++) { cost[i][j] = MAXN; }

		chk = false; 
		for(int i=0 ;i<n; i++) {
			scanf("%s",word); 
			for(int j=0; j<m; j++) 
				if ( word[j] == '1' ){
					if ( !chk ) {
						fst = { i, j} ;
						chk = true; 
					}
					inp[i][j] = true; 
				}
				else 
					inp[i][j] = false; 
		}

		// algorithm goes here

		bfsRestricted( fst.first, fst.second, m, n ); 	// initial pass gets all sources in cands
	
		for(pi el : cands)  // use each candidate not already traversed as source for another traversal 
			if ( cost[el.first][el.second] == MAXN ) 
				bfsRestricted( el.first, el.second, m, n); 

		//

		sizes[t-k-1] = { n, m} ; 
		for(int i=0; i<n; i++) 
			for(int j=0; j<m; j++)  
				resp[t-k-1][i][j] = cost[i][j] ;

		cands.clear(); // cleaning

	}


	for(int k=0; k<t; k++)  {
		for(int i=0; i<sizes[k].first; i++) {
			for(int j=0; j<sizes[k].second; j++)  
				printf("%d ",resp[k][i][j] );
			cout<<endl; 
		}
		if ( k != t-1 ) 
			cout<<endl ;
	}

}

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
	
const int MSIZE = 182; 
const int APP = 10; 

bool bitmap[MSIZE][MSIZE]; 
int resp[MSIZE][MSIZE] ; 


void getSuccessors(queue<pi> &suc, int x, int y , int n, int m) {//filters out whites
	pi dummie; 
			
	if ( x > 0 && !bitmap[x-1][y] ) { 
		dummie.first = x-1;
		dummie.second = y; 	
		suc.push(dummie); 
	}
	if ( x < n-1 && !bitmap[x+1][y] ) { 
		dummie.first = x+1;
		dummie.second = y; 	
		suc.push(dummie); 
	}
	if ( y > 0 && !bitmap[x][y-1] ) { 
		dummie.first = x;
		dummie.second = y-1; 	
		suc.push(dummie); 
	}
	if ( y < m-1 && !bitmap[x][y+1] ) { 
		dummie.first = x;
		dummie.second = y+1; 	
		suc.push(dummie); 
	}
	if ( x > 0 && y > 0 && !bitmap[x-1][y-1] ) { 
		dummie.first = x-1;
		dummie.second = y-1; 	
		suc.push(dummie); 
	}
	if ( x < n-1 && y > 0 && !bitmap[x+1][y-1] ) { 
		dummie.first = x+1;
		dummie.second = y-1; 	
		suc.push(dummie); 
	}
	if ( x > 0 && y < m-1 && !bitmap[x-1][y+1] ) { 
		dummie.first = x-1;
		dummie.second = y+1; 	
		suc.push(dummie); 
	}
	if ( x < n-1 && y < m-1 && !bitmap[x+1][y+1] ) { 
		dummie.first = x+1;
		dummie.second = y+1; 	
		suc.push(dummie); 
	}
}


int getDist(int x, int y, pi rest ) { 
	return resp[x][y] + abs( x - rest.first ) + abs( y - rest.second ) ; 
}

int main() 
{
	int t, n, m, dist, i_, j_, k_; 
	char word[MSIZE];
	bool guard; 
	set< pi > parallel;
	set< pi > :: iterator it; 
	queue< pi > imp_set, help; 
	pi k, j; 

	guard = false;
	
	for (i_=0 ; i_<MSIZE; i_++) { 
		for(j_=0; j_<MSIZE; j_++)  
			resp[i_][j_] = INT_MAX; 
	}


	scanf("%d", &t); 

	for(i_=0; i_<t; i_++) { 
		scanf("%d %d", &n, &m); 

		for (j_=0; j_<n; j_++) { 
			scanf("%s", word); 
			for (k_=0; k_<m; k_++)  {
				bitmap[j_][k_] = (word[k_] == '1')? true : false ; 

				//set whites to 0
				if( bitmap[j_][k_] ) 	
					resp[j_][k_] = 0; 
				else 
					guard = true; 
			}
		}

		if (guard) { 
	
			//this creates first layer of distance update
			for (j_=0; j_<n; j_++) { 		
				for (k_=0; k_<m; k_++) { 
	
					if( bitmap[j_][k_] ) { 
						//find black successors
						getSuccessors(help, j_, k_, n, m );
		
						while ( !help.empty() )  {
							k = help.front(); 
							help.pop(); 

							dist = getDist(j_, k_, k) ; 
	
							//set successor to mincost found
							if ( resp[ k.first ][ k.second ] > dist) {  
								resp[ k.first ][ k.second ] = dist; 

								if ( parallel.count( k ) == 0 ) { 
									parallel.insert(k); 
									imp_set.push(k); 		
								}
							}	
						}
					}
				}
			}
	
	
			//this iterates through each layer until all updated with 
			//minimum distance
			while( !imp_set.empty() ) { 

				k = imp_set.front(); 
				imp_set.pop(); 

				it =  parallel.find( k ) ;
				parallel.erase( it ) ; 
	
				getSuccessors(help, k.first, k.second, n, m ); 
	
				while( !help.empty() ) { 
					j = help.front(); 
					help.pop(); 
					
					dist = getDist(k.first, k.second, j ); 
	
					if ( resp[ j.first ][ j.second ] > dist ) {

						resp[ j.first ][ j.second ] = dist; 
						//reinsert to continue with following layer
						if (parallel.count( j ) == 0 ) { 
							parallel.insert( j ) ; 
							imp_set.push( j ); 	
						}
					}
				}
			}
		}

		for(j_=0; j_<n ; j_++) {

			for(k_=0; k_<m ; k_++){ 	//print output and clear
				cout<<resp[j_][k_];

				resp[j_][k_] = INT_MAX; 
				bitmap[j_][k_] = false; 
			}	
			cout<<endl; 
		}

		guard = false; 
	}

	return 0; 
}

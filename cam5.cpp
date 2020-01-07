#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 

#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define vi vector< pair<int, int> >  
#define vii vector< int, pair<int, int> >

#define MAXS 100000
#define adl vector< vector< int > > 

bool visited[MAXS]; 
int resp[10]; 
	
using namespace std; 

void dfsRec(adl &list, int root, int *number) {
	int i_ ;

	for(i_=0; i_<list[root].size() ; i_++) {

		if ( !visited[ list[root][i_] ] ) { 
			visited[ list[root][i_] ] = true; 	
			*number -= 1; 

			dfsRec(list, list[root][i_], number); 
		}
	}
		
}


void adlInsert(adl &list, int u, int v) { 
	list[u].push_back(v); 
	list[v].push_back(u); 
}	


int main() 
{
	int i_, j_, t, n, e, u_, v_, num;
	adl list; 

	list.reserve(MAXS);

	ri(t); 

	for(i_=0; i_< t ; i_++) {

		ri(n); 
		ri(e); 
		for(j_=0; j_< e ; j_++) {

			rii(u_, v_); 	
			adlInsert(list, u_, v_); 
		}		

		num = n; 
		if (e > 0) { 
			for(j_=0; j_< n ; j_++) {
	
				if ( !visited[j_] ) {
					visited[j_] = true; 
					dfsRec(list, j_, &num); 
				}
			}		
	
			for(j_=0; j_<n ; j_++) {
	
				visited[j_] = false; 	
				list[j_].clear(); 
			}	
		}

		resp[i_] = num; 
	}

	for(i_=0; i_<t ; i_++) 
		cout<<resp[i_]<<endl; 	


	return 0; 
}

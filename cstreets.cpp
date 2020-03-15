#include<iostream> 
#include<stdio.h>
#include<algorithm> 
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

const int NTEST = 100; 
const int MSIZE = 1000; 

int cost[MSIZE] ; 
int sets[MSIZE]; 
int ranks[MSIZE] ;

int resp[NTEST]; 


void addWEdge(vii graph[], int u, int v, int w) { 
	pi temp; 
	
	temp.first = w; 
	temp.second = v; 

	graph[u].push_back( temp ); 
}


int myFind(int e) { 
	int dummie; 

	dummie = e; 

	while ( sets[dummie] != -1) 
		dummie = sets[dummie] ; 

	if ( dummie != e ) 
		sets[e] = dummie; 

	return dummie; 
}


bool myUnion(int x, int y) {
	int rx, ry; 

	rx = myFind(x); 
	ry = myFind(y); 

	if ( rx != ry )  { 
		if ( ranks[ rx ] >= ranks[ ry ] )  {
			sets[ ry ] = rx; 
			if ( ranks[ rx ] == ranks[ ry ] ) 
				ranks[ rx ] += 1; 
		}
		else  
			sets[ rx ] = ry; 

		return true; 
	}
	
	return false; 
}



int myKruskal(vii graph[], int size) { 
	int i_, cost;
	priority_queue< pii, vector<pii>, greater<pii> > best; 
	pii dummie; 

	cost = 0; 
	
	//fill pq with all edges (even simmetric pairs) 
	for(i_=0 ;i_<size ;i_++) { 
		for( pi suc : graph[i_] )  {
			dummie.first = suc.first; 
			dummie.second.first = i_; 
			dummie.second.second = suc.second; 

			best.push( dummie );		
		}
	}

	//pop edges and if their extremes don't belong to the same set,
	//join them and increase cost
	while ( ! best.empty() ) { 
		dummie = best.top(); 
		best.pop(); 

		if ( myUnion(dummie.second.first, dummie.second.second ) )
			cost += dummie.first;		
			
	}

	return cost; 
}

int main() 
{
	int t, p, n, m, a, b, c, i_, j_ ; 
	vii *graph = new vii[MSIZE] ; 

	for(i_=0; i_<MSIZE ; i_++) {
		sets[i_] = -1; 
		ranks[i_] = 0; 	
	}	

	ri(t); 
	for(i_=0; i_<t ; i_++) {
		ri(p); 

		rii(n,m); 
		for(j_=0; j_<m ; j_++) {
			riii(a,b,c); 
			addWEdge(graph, a-1, b-1, c); 
		}		

		resp[i_] = myKruskal(graph, n) * p; 


		for(j_=0; j_<n ; j_++) {
			sets[j_] = -1; 
			ranks[j_] = 0 ;
			graph[j_].clear(); 
		}	
	}

	for(i_=0; i_<t ; i_++) 
		cout<<resp[i_]<<endl; 	

	return 0; 
}

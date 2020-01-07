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


#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 

#define MAXS 10000

using namespace std; 

adl graph;
bool visited[MAXS];

int dfsRec(int root, int parent, int *number) { 
	int i_; 
	bool resp ; 

	resp = true; 

	for(i_=0; i_<graph[root].size() ; i_++) {
		
		if ( !visited[ graph[root][i_] ] )   {
			*number -= 1; 
			visited[ graph[root][i_] ] = true; 
			resp = resp && dfsRec( graph[root][i_], root, number); 
		}
		else if( visited[ graph[root][i_] ] && graph[root][i_] != parent )
			return false; 
	}	

	return resp ;
}
	

void adlInsert(int u, int v) { 
	graph[u].push_back(v); 
	graph[v].push_back(u); 
}

int main() 
{
	int i_, n_, m_, u, v, conex; 
	bool loops ;

	rii(n_, m_);
	conex = n_ - 1; 

	graph.resize(n_); 
	visited[0] = true;

	for(i_=0; i_<m_ ; i_++) {
		rii(u,v); 
		adlInsert(u-1,v-1);		
	}

	loops = dfsRec(0, 0, &conex); 

	(!loops || conex != 0)? cout << "NO"<<endl: cout << "YES"<<endl;

	return 0; 
}

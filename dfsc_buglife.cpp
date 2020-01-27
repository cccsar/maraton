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
#define rw(s) scanf("%s",&s)
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 

using namespace std; 

#define MAXS 2000
int visited[MAXS]; 
int color[MAXS]; 
bool resp[10000];

adl graph;

int mex(adl &graph, int r, int *imp){ 
	ref, mx; 
	set<int> help; 
	set<int>::iterator it; 

	mx = 0;
	

	for(auto i_: graph[r] ) {
		if ( color[ i_ ] != -1) 
			help.insert( color[i_] );
	}

	if ( help.size()  == 0)
		return 0 ;
	else {
		ref = 0; 
		for (it = help.begin(); it!=help.end(); it++)  {
			if (*it != ref) 
				break ;
			ref ++;
		}

		mx = ref - (it == help.end() )? 0: 1;
		/*if ( *it == help.end()) */
			/*mx = ref; */
		/*else */
			/*mx = ref -1; */

		if (mx > *imp ) 
			*imp = mx ; 

		return mx ;
	}
}

void dfsRec(adl &graph, int r, int* imp) { 

	color[r] = mex(graph, r, imp); 

	for(auto i_: graph[r]) {
		if (!visited[i_]) { 
			visited[i_] = true; 
			dfsRec(graph, i_, imp); 
		}
	}		

}




int main() 
{
	int i_, j_, q, n, m, u, v, imp; 

	imp = 0; 
	for(i_=0; i_<2000 ; i_++){
		color[i_] = -1; 	
	}

	graph.reserve(MAXS);
	ri(q); 

	for(i_=0; i_<q ; i_++) {

		rii(n,m); 	
		for(j_=0; j_<m ; j_++) {
			rii(u,v); 

			graph[u-1].push_back(v-1);	
			graph[v-1].push_back(u-1);	
		}	

		for(j_=0; j_<n ; j_++) {
			if(!visited[j_]){
				visited[j_] = true; 
				dfsRec(graph, j_, &imp); 
			}
		}	

		resp[i_] = (imp > 1)? true: false; 

		for(j_=0; j_<n ; j_++) {
			cout<<color[j_]<<" ";	
		}	
		cout<<endl; 

		for(j_=0; j_<n ; j_++) {
			graph[j_].clear();
			visited[j_] = false; 	
			color[j_] = -1; 
		}	

	}

	for(i_=0; i_<q ; i_++) {
		cout<<"Scenario #"<<i_<<":"<<endl; 
		if (resp[i_])
			cout<<"Suspicious bugs found!"; 
		else
			cout<<"No suspicious bugs found!";
		cout<<endl; 	
	}


	return 0; 
}

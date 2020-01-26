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

int parent[MAXS]; 
int ranks[MAXS];
bool resp[10000]; 


int myFind(int e ) { 
	int dummie; 
	dummie = e; 

	while ( parent[dummie] != -1) {
		dummie = parent[ dummie ] ; 
	}
		

	if ( dummie != e )  
		parent[e] = dummie ;

	
	return dummie; 
}	


bool myUnion(int x, int y, int size) { 
	int rx, ry, count, i_; 

	rx = myFind(x); 
	ry = myFind(y); 

	if (rx != ry ){ 
		if ( ranks[ rx ] >= ranks[ ry ] ) {
			parent[ ry ] = rx; 
			
			if (ranks[rx] == ranks[ry])  
				ranks[rx] ++;
		}
		else  
			parent[rx] = ry; 
	}
	else  {
		count = 1;

		//this increases order
		for (i_=0; i_<size; i_++) {
			if(parent[i_] == rx)
			       count++; 	
		}

		if (count%2 == 1) 
			return true; 
	}


	return false; 
}


int main() 
{
	int i_, j_, q, n, m, u, v; 
	
	ri(q); 

	for(i_=0; i_<MAXS ; i_++) 
		parent[i_] = -1; 	

	for(i_=0; i_<q ; i_++) {
		rii(n,m); 

		if(n == 1) 
			resp[i_] = true; 
		else {
			for(j_=0; j_<m ; j_++) {
				rii(u,v);
	
				resp[i_] = resp[i_] || myUnion(u-1, v-1, n); 
			}	
	
			for(j_=0; j_<n ; j_++) {
				parent[j_] = -1; 
				ranks[j_] = -1; 	
			}
		}
	}

	for(i_=0; i_<q ; i_++) {
		cout<<"Scenario #"<<i_+1<<":"<<endl;
		if( resp[i_] )
			cout<<"Suspicious bugs found!";
		else 
			cout<<"No suspicious bugs found!";
		cout<<endl; 
	}

	return 0; 
}

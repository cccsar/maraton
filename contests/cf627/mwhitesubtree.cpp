/*
 * https://codeforces.com/contest/1324/problem/F
 * cccsar
 */
#include<stdio.h> 
#include<iostream> 
#include<vector> 

#define MAXN 2*200000

using namespace std; 

bool color[MAXN];
int backt[2][MAXN], post[2][MAXN], parent[2][MAXN] ,diag[2][MAXN] ; 
int resp[MAXN-1] ; 
vector<int> * tree = new vector<int> [MAXN]; 

int dfsRec(int source, int dg, int ind) { 
	cout<<source<<" "<<dg<<" "<<ind<<endl; 

	if ( color[source] ) 
		backt[ind][source] = backt[ind][ parent[ind][source] ] + 1;  
	else 
		backt[ind][source] = (backt[ind][ parent[ind][source] ] > 1)? backt[ind][ parent[ind][source] ] - 1: 0; 

	diag[ind][source] = diag[ind][ parent[ind][source] ] + dg; 

	int help = 0; 
	if (ind == 0) { 
		for(int ady : tree[source])  
			if ( parent[ind][ ady ] == -1 ) { 
				parent[ind][ady] = source; 
				help += dfsRec(ady, help, ind) ; 
			}
	}
	else { // reverse order of ady traversal 
		for(int i=tree[source].size()-1; i>= 0; i--)    
			if ( parent[ind][ tree[source][i] ] == -1 ) { 
				parent[ind][ tree[source][i] ] = source; 
				help += dfsRec( tree[source][i] , help, ind) ; 
			}
	}

	post[ind][source] = help ;  
	return (color[source])? post[ind][source] + 1 : (post[ind][source] > 1)? post[ind][source] -1 : 0;    
} // can't handle path of length >2 with black nodes

int main() { 
	int n, u, v, e , beg;

	cin >> n; 

	for(int i=0 ;i<n; i++)   // init
		parent[0][i] = parent[1][i] = -1 ; 
	
	for(int i=0; i<n; i++) { 
		cin >> e; 
		if (e) { 
			color[i] = true; 
			beg = i; 
		}
		else 
			color[i] = false; 
	}	

	for(int i=0 ;i<n-1;  i++) { 
		cin >> u >> v;
		tree[u-1].push_back( v-1 ); 
		tree[v-1].push_back( u-1 ); 
	}

	parent[0][beg] = beg; 
	backt[0][beg] = diag[0][beg] = 0; 
	dfsRec(beg, 0, 0); 

	parent[1][beg] = beg; 
	backt[1][beg] = diag[1][beg] = 0; 
	dfsRec(beg, 0, 1); 

	for(int i=0; i<n; i++) cout<<backt[0][i]<<" "; 
	cout<<endl; 
	for(int i=0; i<n; i++) cout<<post[0][i]<<" "; 
	cout<<endl; 
	for(int i=0; i<n; i++) cout<<diag[0][i]<<" "; 
	cout<<endl; 

	cout<<endl; 
	for(int i=0; i<n; i++) cout<<backt[1][i]<<" "; 
	cout<<endl; 
	for(int i=0; i<n; i++) cout<<post[1][i]<<" "; 
	cout<<endl; 
	for(int i=0; i<n; i++) cout<<diag[1][i]<<" "; 
	cout<<endl; 

	for(int i=0 ;i<n; i++) cout<< backt[0][i] + post[0][i] + diag[0][i] + diag[1][i]<<" ";
	cout<<endl; 




}

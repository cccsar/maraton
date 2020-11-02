/*
 * https://codeforces.com/contest/1324/problem/F
 * cccsar
 */
#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<set> 

using namespace std; 

const int MAXN = 2*200000; 

bool color[MAXN];
int backt[2][MAXN], post[2][MAXN], parent[2][MAXN] ,diag[2][MAXN] ; 
set<int> *atree = new set<int> [MAXN], *btree = new set<int> [MAXN] ;


int dfsRec(int source, int dg, int ind, set<int> *&tree) { 
	int pp = parent[ind][source];

	if ( color[source] ) 
		backt[ind][source] = backt[ind][ pp ] + 1;  
	else 
		backt[ind][source] = (backt[ind][ pp ] > 1)? backt[ind][ pp ] - 1: 0; 

	if ( !color[ pp ] && !color[source]  ) {
		if ( diag[ind][ pp ] + dg > 1 ) 
			diag[ind][source] = diag[ind][ pp ] + dg - 1;
		else 	
			diag[ind][source] = 0; 
	}
	else 
		diag[ind][source] = diag[ind][ pp ] + dg ;

	int help = 0; 
	int curr; 
	for(int el : tree[source]) { 
		curr = (ind == 0)? el : -el ; 
		if ( parent[ind][curr] == -1 ) { 
			parent[ind][curr] = source; 
			help += dfsRec(curr, help, ind, tree); 
		}
	}

	post[ind][source] = help ;  

	return (color[source])? post[ind][source] + 1 : (post[ind][source] > 1)? post[ind][source] -1 : 0;    
} 

int main() { 
	int n, u, v, e , beg;

	cin >> n; 

	for(int i=0 ;i<n; i++)   // init
		parent[0][i] = parent[1][i] = -1 ; 
	
	beg = -1; 
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
		atree[u-1].insert( v-1 )    , atree[v-1].insert( u-1)  ;
		btree[u-1].insert( -(v-1) ) , btree[v-1].insert( -(u-1) ) ;
	}


	if ( beg == -1) {
		for(int i=0 ;i<n; i++) cout<<0<<" "; 
		cout<<endl; 
	}
	else { 
		parent[0][beg] = beg; 
		backt[0][beg] = diag[0][beg] = 0; 
		dfsRec(beg, 0, 0, atree); 

		parent[1][beg] = beg; 
		backt[1][beg] = diag[1][beg] = 0; 
		dfsRec(beg, 0, 1, btree); 

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

		cout<<endl; 
		for(int i=0; i<n; i++) cout<<parent[0][i]<<" "; 
		cout<<endl; 
		for(int i=0; i<n; i++) cout<<parent[1][i]<<" "; 
		cout<<endl; 
		cout<<endl; 

		for(int i=0 ;i<n; i++) cout<< backt[0][i] + post[0][i] + diag[0][i] + diag[1][i]<<" ";
		cout<<endl; 
	}




}

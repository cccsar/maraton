#include "graphs_.hpp"
#include<stdio>
#include<set> 

using namespace std;


/* List of included graph functions: 
 *
 * Done: 
 * 	general: 
 *		load_graph
 * 		print_graph
 * 	reach:
 * 		reach_brute_force
 * 		roy_warshall
 * 		comp_conex
 * Yet to do: 
 * 	MST:
 * 		prim (v1 & v2) 
 * 		kruskal (v1 & v2) 
 * 	graph traversal:
 * 		dfs (rec and some other imp)
 * 		dfs visit
 * 		bfs
 * 		backtracking
 *
 * 	Not seen graph functions
 *
 * This is a work-in-progress graph library for reviewing contents of my algorithms III course (which I suspended). I hope this 
 * grows to incorporate every alogrithm given in the course, with smart, optimized (I'm aiming high) implementation and
 * readable and understandeable documentation and simultaneously, helps me pass the subject and learn about library development.
 * 
 * XOXO
 *
 * cCc
 *
 * PD: don't forget to update namespaces for every included function. Set in comp_conex() is giving trouble
 */

void load_graph(vector< vector<bool> > &in_m, int size, int n_edges)
{
	
	//Enabling enough capacity for the 2D vector to work
	in_m.resize(size); 
	
	for(int i=0; i<size; i++) { 
		in_m[i].resize(size); 
		in_m[i][i] = true; 	//adding Identity
	}

	int a,b; 
	for(int j=0; j<n_edges; j++) { 
		cin>>a>>b; 
		in_m[a][b] = true;
	}	
}


void print_graph(vector< vector<bool> > &in_m, int size)
{
	for(int k=0; k<size; k++) { 
		for(int l=0; l<size; l++) { 
			cout<<in_m[k][l]<<" "; 	
		}	
		cout<<endl; 
	}	

}


void reach_brute_force(vector< vector<bool> > &in_m, int size)
{
	vector< vector<bool> > aux_m; 

	//This is created to add the l-th reach relation to the input adjacency matrix.
	aux_m.resize(size);
	for(int p=0; p<size; p++) { 
		aux_m[p].resize(p); 
	}

	/* Main algorithm:
	 *	Input: 	Adjacency matrix
	 *	Output: Reach matrix 
	 *
	 *	It searches through every file for an edge (k,j) (with 0<=i,j<n) and then, search for edges (j,i) at j file,
	 *	if found, in_m[j][i] is considered reachable and include to the l-th relation of reach.
	 *
	 *	-Order: O(n^4)
	 *	-Propositions involved: 
	 *		Recursive definition of a relation. 
	 *		" Let G=(V,E) be a (di)graph and n=|V|. For all m in N, if {v,w} is in E^m, then {v,w} is in E^(n-1) "
	 *	-Termination: It is formed by nested loops bounded by finite numbers, it will end.  
	 *	-Correcteness: --> unfinished 
	 */

	for(int l=1; l<size-1; l++) {
		for(int k=0; k<size; k++) {
			for(int j=0; j<size; j++) {

				if (in_m[k][j] == 1)
				{
					for(int i=0; i<size; i++) {
	
						if (in_m[j][i] == 1)
							aux_m[k][i] = 1; 
					}
				}
			}
		}
	
		for(int c=0; c<size; c++){ 
			for(int r=0; r<size; r++) { 
				in_m[c][r] = in_m[c][r] | aux_m[c][r]; 
			}
		}
			
	}	
	
}



void roy_warshall(vector< vector<bool> > &in_m, int size)
{
	/*Main Algorithm: 
	 * 	-Input: Adjacency matrix
	 *	-Output: Reach matrix
	 *	
	 *
	 *
	 *	-Order: O(n^3)
	 *	-Propositions involved: 
	 *		Weird relation definition
	 *		" Let G=(V,E) be a graph , v,w belonging V and 0<=k<=|V|. If (v,w) doesn't belong to E_k-1, then 
	 *		(v,w) belongs to E_k if and only if exist a v_k in V such that (v,v_k) belongs to E_k-1 
	 *		and (v_k,w) to E_k-1 "
	 *	-Termination: Inmediate 
	 *	-Correctness: --> not finished
	 */
	
	for (int k=0; k<size; k++) { 
		for(int j=0; j<size; j++) { 
			for(int i=0; i<size; i++) { 
				in_m[i][j] = in_m[i][j] | (in_m[i][k] && in_m[k][j]) ;	
			}
		}
	}	
	
}


int comp_conex(vector< vector<bool> > reach_m, vector< vector<int> > &resp, int size)
{
	/*Main algorithm: 
	 *
	 * 	-Input: Reach matrix
	 * 	-Output: Conex components of a graph
	 *
	 * 	It uses a set to represent the elements of the graph and iterates while the set is not empty, using the d-th element
	 * 	of the set as a "representative" whose reacheable nodes are calculated in O(n) time using the reach matrix.
	 * 	
	 * 	Since it requires the reach matrix, the preprocessing pushes the time bound to O(n^3) (Roy-Wharshall).
	 *
	 * 	-Order: 
	 * 		>>Time: O(k*n) where k is the number of conex components and n=|V|
	 * 		>>Memory: 
	 * 	-Propositions Involved: None
	 * 	-Termination: For every node, whithin the internal loop it is garanteed that at least one node will be deleated from
	 * 	the set (since for all i such 0<=i<n, in_m[i][i] == true), thus the while condition is guaranteed to be false 
	 * 	eventually.
	 * 	-Correctness: A conex component is defined as the induced graph from every partition of V derived from the mutual 
	 * 	reach relation. This algorithm verifies for a node, wheter the elements it reaches, reach it as well (mutual reach),
	 * 	and then it groups them in the same vector (which ressembles a partition). Thus this algorithm.....
	 */ 

	resp.resize(size);
	set<int ,set<int> > sect; 
	
	for(int c=0; c!=size; c++) {
		sect.insert(c); 
	}

	set<int, set<int> >::iterator d; 
	int node, count; 
	count = 0; 
	while ( !sect.empty() )	{
		d = sect.begin(); 
		node = *d; 

		for(int r=0 ; r!=size ;r++) { 
			
			if(reach_m[node][r] && reach_m[r][node])
			{
				resp[count].push_back(r); 
				sect.erase(r);
			}
		}
		count++; 
	}
	
	return count;
}

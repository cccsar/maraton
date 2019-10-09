
#include<iostream> 
#include<vector>

using namespace std; 

// Practice implementation for graph algorithm. This is only to set a baseline on what will be specified
// on future graph algorithm implementations

void load_graph(vector< vector<bool> > &in_m, int size, int n_edges); 
void reach(vector< vector<bool> > & in_m, int size); 
void print_graph(vector< vector<bool> > &in_m, int size); 

int main() 
{ 
	vector< vector<bool> > cc; 
	int n,e; 
	cin>>n; 
	cin>>e; 

	load_graph(cc, n, e);	

	reach(cc, n); 

	print_graph(cc, n); 


	return 0; 
}


void reach(vector< vector<bool> > &in_m, int size)
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

/* Input type: 
 	n
	e
	v_1 w_1
	v_2 w_2
	.
	.
	v_e w_e
*/

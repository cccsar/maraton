#include<iostream> 
#include<set> 
#include<vector>
#include<list>

using namespace std; 

void load(vector< vector<bool> > &in_m, int size, int n_edges);
void print(vector< vector<bool> > &in_m, int size);
void roy_warshall(vector< vector<bool> > &in_m, int size); 
int comp_conex(vector< vector<bool> > reach_m, vector< vector<int> > &resp, int size);

int main() 
{ 
	vector< vector<bool> > in_m;
	vector< vector<int> > results; 
	int n, e; 
	
        cin>>n>>e; 

	load(in_m, n, e); 

	roy_warshall(in_m, n); 
	
	int stop = comp_conex(in_m, results, n);

	for(int i=0; i<stop; i++) { 
		for(int j=0; j<results[i].size(); j++) { 
			cout<<results[i][j]<<" "; 
		}
		cout<<endl;
	}

	
	return 0; 
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
	set<int ,less<int> > sect; 
	
	for(int c=0; c!=size; c++) {
		sect.insert(c); 
	}

	set<int, less<int> >::iterator d; 
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

void roy_warshall(vector< vector<bool> > &in_m, int size)
{
	
	for (int k=0; k<size; k++) { 
		for(int j=0; j<size; j++) { 
			for(int i=0; i<size; i++) { 
				in_m[i][j] = in_m[i][j] | (in_m[i][k] && in_m[k][j]) ;	
			}
		}
	}	
	
}


void load(vector< vector<bool> > &in_m, int size, int n_edges)
{
	
	in_m.resize(size); 
	for(int i=0; i<size; i++) { 
		in_m[i].resize(size); 
		in_m[i][i] = true; 	
	}

	int a,b; 
	for(int j=0; j<n_edges; j++) { 
		cin>>a>>b; 
		in_m[a][b] = true;
	}	

}


void print(vector< vector<bool> > &in_m, int size)
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

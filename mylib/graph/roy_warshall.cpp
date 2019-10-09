#include<iostream> 
#include<vector>

using namespace std; 

void load(vector< vector<bool> > &in_m, int size, int n_edges);
void print(vector< vector<bool> > &in_m, int size);
void roy_warshall(vector< vector<bool> > &in_m, int size); 

int main() 
{ 
	vector< vector<bool> > ccc; 
	int n, e; 
	cin>>n>>e; 	

	load(ccc, n, e); 
	
	roy_warshall(ccc, n); 
		
	print(ccc, n); 


	return 0; 
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

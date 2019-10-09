
#include<iostream> 
#include<vector>
#include<utility> 
#include<set> 
#include<iterator> 
#include<algorithm>
#include<climits>


using namespace std; 

void kruskal(vector< vector<int> > in_m, int size, vector<int> &parents, int root);
void update_adyacents(vector< vector<int> > in_m, int size, vector<int> cut, set<int> sect, vector<int> &weights, int node);
int min_weight(vector<int> weights, set<int> tiles);
void load_weighted(vector<vector<int> > &in_m, int size, int edge);


int main() 
{ 
	vector< vector<int> > graph;
	vector<int> parent_v; 
	int n, e, r;
	cin>>n>>e; 

	load_weighted(graph, n, e); 

	parent_v.resize(n);
	for(int i=0; i<n; i++) { 
		parent_v[i] = -1; 
	}
	
	cin>>r; 
	kruskal(graph, n, parent_v, r); 

	for(int j=0; j<n; j++) { 
		cout<<parent_v[j]<<" "; 
	}
	cout<<endl; 

	return 0; 
}


void load_weighted(vector<vector<int> > &in_m, int size, int edge)
{
	in_m.resize(size); 
	for(int i=0; i<size; i++) {
		in_m[i].resize(size); 
	}

	int u,v,p; 
	for(int j=0; j<edge; j++) { 

		cin>>u>>v>>p; 
		in_m[u][v] = p; 
	}
}


void kruskal(vector< vector<int> > in_m, int size, vector<int> &parents, int root)
{
	vector<int> weights; 
	set<int> sect; 
	int current;

	parents[root] = root; 
	weights.resize(size); 
	for(int r=0; r<size; r++) { 
		weights[r] = INT_MAX; 
	}
	current = root;

	int aux;
	for(int c=0; c<size; c++) { 
	
		update_adyacents(in_m, size, parents, sect, weights, current); 

		aux = min_weight(weights, sect); 

		parents[aux] = current; 
		sect.erase(aux); 
		weights[aux] = INT_MAX; 
		current = aux; 

	}		
}


void update_adyacents(vector< vector<int> > in_m, int size, vector<int> cut, set<int> sect, vector<int> &weights, int node)
{
	for(int c=0; c<size; c++){

		if (in_m[node][c] != 0)
		{
			if (cut[c] == -1)
			{
				if (weights[c] > in_m[node][c]) 
				{ 
					weights[c] = in_m[node][c]; 
					sect.insert(c); 
				}
					
			}
		}
	}

}

int min_weight(vector<int> weights, set<int> tiles)
{

	int l, ind;  
	l = INT_MAX; 
	set<int>::iterator it; 
	for(it=tiles.begin(); it!=tiles.end(); it++) { 
		
		if (weights[*it] < l)
		{
			l = weights[*it];
			ind = *it; 
		}
	}

	return ind; 
}


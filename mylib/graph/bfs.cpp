#include <stdio.h> 
#include <iostream> 
#include <deque> 
#include <vector> 

#define NODE_CEIL 100

using namespace std; 

deque<int> waiting; 
vector<int> visited; 
vector< vector<bool> > adj_mat; 


void input_mat(vector< vector<bool> > &mat, int n_edges) {
	int j,u,v;
	for(j=0; j<n_edges; j++) {
		cin>>u>>v; 
		mat.at(u).at(v) = true; 
		mat.at(v).at(u) = true; 
	}
}


void get_suc(vector< vector<bool> > mat, vector<int> &suc_list,  int el, int size) { 
	int k; 
	
	for (k=0; k<size; k++) { 
		if( mat[el][k] == true )  
			suc_list.push_back(k); 
	}
}


bool vect_contains(vector<int> vect, int el) { 
	int x;
	for(x=0; x<vect.size(); x++)  {
		if (vect[x] == el)
			return true;
	}

	return false; 
}

bool deque_contains(deque<int> de, int el ) { 
	int y; 
	for(y=0; y<de.size(); y++) { 
		if (de[y] == el) 
			return true; 
	}

	return false; 
}

int main() {

	/*	allocating space for adj_mat	*/
	adj_mat.resize(NODE_CEIL); 
	int i; 
	for(i=0; i<NODE_CEIL; i++) 
		adj_mat[i].resize(NODE_CEIL);
	

	/*	initialice matrix 	*/
	int n,m;
	cin>>n>>m; 
	input_mat(adj_mat, m); 
	
	/*	root of bfs 	*/
	int root; 
	cin>>root; 
	
	/*	begin bfs 	*/ 
	vector<int> sucs; 
	waiting.push_back(root);
	int dummie; 
	while( visited.size() != n ) { 

		if (waiting.size() == 0) 
			break;

		dummie = waiting.front(); 
		visited.push_back(dummie); 
		waiting.pop_front();

		get_suc(adj_mat, sucs, dummie, n); 
		int k; 
		while (sucs.size() != 0) { 

			//La segunda parte de este if me la chuletee, shame on me, no se me ocurrio que tuviese carga
			if( !vect_contains(visited,sucs.back()) && !deque_contains(waiting,sucs.back()) )
				waiting.push_back( sucs.back() ); 

			sucs.pop_back(); 

		}

		       				
	}	

	int c; 
	for(c=0; c<visited.size(); c++)  
		cout<<visited[c]<<endl; 
		
	return 0;
}

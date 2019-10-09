#include<iostream> 
#include<vector> 
#include<set> 
#include<queue> 

using namespace std; 

void load_weighted(vector<vector<int> > in_m, int size, int edges); 
void prim(vector<vector<int> > in_m, int size, int root); 

int main() 
{ 

	return 0; 
}

void load_weighted(vector<vector<int> > &in_m, int size, int edge)
{
	in_m.resize(size); 
	for(int i=0; i<size; i++) {
		in_m[i].resize(size); 
	}

	int u,v,p; 
	for(int j=0; j<edges; j++) { 

		cin>>u>>v>>p; 
		in_m[u][v] = p; 
	}
}

void prim(vector<vector<int> > in_m, int size, int root)
{


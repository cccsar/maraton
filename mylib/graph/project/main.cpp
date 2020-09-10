
#include<iostream> 
#include<vector>
#include "./source/graphs_.cpp" 

using namespace std; 

int main() 
{ 
	vector< vector<bool> > p_matrix; 
	int n, e; 
	cin>>n>>e; 
	
	load(p_matrix, n, e); 

	print(p_matrix, n); 

	return 0; 
}

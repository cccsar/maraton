
#include<iostream> 
#include<stdio.h> 
#include<string>
#include<vector> 
#include<bitset> 
#include<algorithm> 

using namespace std; 

void load(vector< vector<bool> > &m, int size, int edges); 
vector<int> suc(int t, vector< vector<bool> > m);
//vector<int> dfs(int t, vector< vector<int> > m);
//void recover(); 

int main() 
{ 
	int n,e; 
	vector< vector<bool> > graph; 

	cin>>n>>e; 
	
	load(graph, n, e); 	

	/* print graph
	for(int qk=0; qk<n; qk++) { 
		for(int ck=0; ck<n; ck++) { 
			cout<<graph[qk][ck]<<" "; 
		}
		cout<<endl ;
	}
	*/

/*
	int r; 
	vector<int> p;

	p.resize(n);
	p[0] = 0; 
	for (int k=1; k<n; k++) { 
		p[k] = -1; 
	}
	
	cin>>r;

	dfs(graph, r, p); 	
*/	
	return 0; 
}

void load(vector< vector<bool> > &m, int size, int edges)
{ 
	//Performing a sort of "allocation" to save the necessary space we will use for the vector
	m.resize(size);
	for(int i=0; i<size; i++) { 
		m[i].resize(size); 
	}	
	
	int a,b;
	for(int j=0; j<edges; j++) { 
		cin>>a>>b; 
		m[a][b] = true; 
	}	
} 

vector<int> suc(int t, vector< vector<bool> > m) 
{	
	vector<int> sons; 
	for(int l=0; l<m.size(); l++) { 
		
		if (m[t][l])
		{
			sons.push_back(l) ;
		}
	}
	
	return sons; 	
}

vector<int> dfs(int t, vector< vector<int> > m, vector<int> parents) { 

}

//void recover()
//{
//}

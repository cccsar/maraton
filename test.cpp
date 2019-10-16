#include <iostream> 
#include <stdio.h>
#include <vector> 

using namespace std; 

#define FOR(n) for(int i=0; i<n; i++) 
#define ROF(n) for(int i=n; i>0; i--) 
#define rint(c) scanf("%d",&c)

typedef vector< vector<int> > adyl; 


adyl perico(100); 


vector<int> func() { 

	vector<int> hola; 
	FOR(10)  
		hola.push_back(i);

	return hola; 
}


int main() 
{

	vector<int> drogas; 
	perico[0].push_back(3); 

	FOR(perico.size()) 
		perico[i].push_back(i); 

	cout<<sizeof(perico)<<endl; 

	FOR(perico.size()) 
		cout<<sizeof(perico[i])<<endl;

	//test values of 2nd dimention vector in nested vector type
	//test vector asignacion as return value for a function using = operator.. it works.. is if eff?
    

    return 0; 
}

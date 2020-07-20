
#include<iostream> 
#include<stdio.h>
#include<string> 
	
using namespace std; 

int main() 
{
	
	int n;
	cin>>n; 
	int x,y,aux;
	int resp[n];

	for (int c=0; c<n; c++) { 
		
		cin>>x>>y; 
		if ( x==y || x==2+y)
		{
			resp[c] = ( x%2==0 )? x + y: x + y - 1;
		}
		else { 
			resp[c] = -1;
		}
	}

	for (int i=0; i<n; i++) { 

		if (resp[i]==-1) 
		{
			cout<<"No Number"<<endl; 
		}
		else { 
			cout<<resp[i]<<endl; 
		}
	}

	return 0; 
}

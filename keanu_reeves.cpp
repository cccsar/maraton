#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

int main() 
{
	int n; 
	string s; 
	
	cin>>n; 
	cin>>s; 

	int z, o; 
	z = o = 0; 
	for (int c=0; c<n; c++) { 
		
		(s[c]=='0')? z++: o++; 
	}

	int aux; 
	if (o != z) 
	{
		cout<<"1"<<endl; 
		cout<<s<<endl; 
	}
	else { 
		int rz, ro; 
		rz = ro = 0; 

		for (int i=0; i<n; i++) {
			
			(s[i] == '0')? rz++: ro++; 

			if ( ro != rz && o-ro != z-rz ) 
			{
				aux = i; 
				break;
			}
		}

		int tam = s.length(); 
		cout<<"2"<<endl ;
		cout<<s.substr(0,aux+1)<<" "<<s.substr(aux+1, tam-1)<<endl; 	
	}
	


	return 0; 
}


#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

int main() 
{
	string XX[1000];  	
	int v[1000];
	int count = 0; 
	int a,b,c; 
		
	while(true) { 
		
		cin>>a>>b>>c; 
		if (a==0 && b==0 && c==0)
		{
			break; 
		}

		if (b-a == c-b) 
		{
			XX[count] = "AP"; 
			v[count] = c + b-a; 
		}
		else { 
			XX[count] = "GP"; 
			v[count] = c*b/a; 
		}
				
		count++;			
	}

	for (int c=0; c<count; c++) {
		cout<<XX[c]<<" "<<v[c]<<endl; 
	}

	return 0; 
}


#include<iostream> 
#include<string>

using namespace std; 


int main() 
{
	string a,b; 
	cin>>a>>b;
	int count,neven;
	int diff = a.size() - b.size(); 
	
	neven = 0; 
	for (int i=0; i<=diff; i++) { 
		
		count = 0;	
		for (int j=i; j<b.size()+i; j++)  {
			
			if (a[j] != b[j-i])
			{
				count++; 
			}
		}	
		
		if (count%2 == 0) 
		{
			neven ++; 
		}
	} 

	cout<<neven<<endl; 
	
	return 0; 
}


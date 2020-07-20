
#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

bool isAmbiguous(int perm[], int size);

int main() 
{
	int n; 
	int c = 0; 
	string resp[1000];
	
	while(true) { 
		cin>>n; 
		int num[n];

		if (n == 0) {
			break; 
		}
	
		for (int i=0; i<n; i++){ 
			cin>>num[i];
		}
		
		resp[c] = (isAmbiguous(num, n))? "ambiguous":"not ambiguous"; 
		c++;
	}
		
	for (int j=0; j<c; j++) {
		cout<<resp[j]<<endl; 
	}
	return 0; 
}

bool isAmbiguous(int perm[], int size) { 

	for (int k=0; k<size; k++) { 
		
		if ( k+1 != perm[ perm[k] - 1 ] ) 
		{
			return 0;
		}
	}
	
	return 1;	
}

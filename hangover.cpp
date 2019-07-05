#include<iostream> 

using namespace std; 

int harmonic(float x){ 
	float c = 0.00; 
	int j = 2; 
		
	while (c <= x) { 
		c += 1.00/(float)j ; 
		j ++; 
	}
	
	return j - 2; 
}	
	

int main() 
{
	float arr[1000] ;
	float current = -1.00;
	int n = 0;

	while( current != 0.00 )
	{
		cin>>arr[n]; 
		current = arr[n];
		n++;
	}
	
	n--;
	
	for (int i=0; i<n; i++) { 
		cout<<harmonic(arr[i])<<" card(s)"<<endl; 
	}

	return 0;
}

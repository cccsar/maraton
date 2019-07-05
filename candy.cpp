
#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

int isDivisible(int candies[], short size); //if it is ret quotient, else ret -1
int movesCount(int candies[], short size, short comp); 

int main() 
{
	int c = 0; 
	int resp[10000];
	int n;
	int equals; 

	while (true) {
		
		cin>>n; 
		if (n == -1) 
		{
			break; 
		}

		int arr[n];

		for (int i=0; i<n; i++) {
			cin>>arr[i]; 
		}
	
		equals = isDivisible(arr, n); 	
		resp[c] = (equals != -1)? movesCount(arr,n,equals): -1; 
	
		c++; 
	}	

	for (int i=0; i<c; i++) {
		cout<<resp[i]<<endl;
	}		

	return 0; 
}

int isDivisible (int candies[], short size) { 
	int sum = 0;

	for (int j=0; j<size; j++) { 
		sum += candies[j]; 
	}
	
	return (sum%size == 0)? sum/size: -1; 
}


int movesCount(int candies[], int size, int comp) {
	int counter = 0;
	
	for (int k=0; k<size; k++) { 
		
		if (candies[k]<comp) { 
			counter += comp - candies[k]; 
		}
	}	
	return counter;
}

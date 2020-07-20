
#include<iostream> 
#include<stdio.h> 
#include<queue>
#include<string> 
	
using namespace std; 

int isDivisible(int candies[], int size); //if it is ret quotient, else ret -1
int movesCount(int candies[], int comp, int size); 

/* This program tells for a given amount of candy bags n, and the amount of candies on it arr[n], the minimum number of
	moves to make all candy bags have the same amount of candies. If it is not possible to have the same amount of candies
	it returns -1. A move is considered as taking a "single" candy from one bag and moving it to another one.
*/
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
		resp[c] = (equals != -1)? movesCount(arr,equals, n): -1; 
	
		c++; 
	}	

	for (int i=0; i<c; i++) {
		cout<<resp[i]<<endl;
	}		

	return 0; 
}

int isDivisible (int candies[], int size) { 
	int sum = 0;

	for (int j=0; j<size; j++) { 
		sum += candies[j]; 
	}
	
	return (sum%size == 0)? sum/size: -1; 
}


int movesCount(int candies[], int comp, int size) {
	int counter = 0;

	for (int k=0; k<size; k++) { 
		
		if (candies[k]<comp) { 
			counter += comp - candies[k]; 
		}
	}	
	return counter;
}


#include<iostream> 
#include<stdio.h> 
#include<queue>
#include<string> 
	
using namespace std; 

int isDivisible(int candies[], int size); //if it is ret quotient, else ret -1
int movesCount(int candies[], int size, int comp); 

/* This program tells for a given amount of candy bags n, and the amount of candies on it arr[n], the minimum number of
        moves to make all candy bags have the same amount of candies. If it is not possible to have the same amount of candies
        it returns -1. A move is considered as taking a bunch of candes from one bag and moving it to another one.
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
		resp[c] = (equals != -1)? movesCount(arr,n,equals): -1; 
	
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


int movesCount(int candies[], int size, int comp) {
	
	int counter = 0;
	priority_queue<int> cup; 
	priority_queue<int> water; 
	
	for (int k=0; k<size; k++) { 
		
		if (candies[k] < comp)
		{
			cup.push(comp - candies[k]); 
		}
		else if (candies[k] > comp) 
		{
			water.push(candies[k] - comp); 
		}
	}	

	int p,q; 
	bool brk = true;
	while (!cup.empty() || !water.empty()) { 
		if (brk == true)
		{
			p = cup.top();
			cup.pop(); 
		}

		q = water.top(); 
		water.pop(); 

		if (q >= p) { 
			q -= p; 

			if (q > 0) 
			{
				water.push(q); 
			}

			counter++; 
			brk = true;
		}
		else { 
			p -= q;
			brk = false; 
		}
	}
	
	return counter;
}

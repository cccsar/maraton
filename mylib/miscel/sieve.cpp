
#include<iostream> 
#include<stdio.h> 
#include<math.h>
#include<string>
#include<algorithm> 

#define TOO_BIG 100000000
//Apparently this shit can go all the way with no O(something) of memory

int arr[TOO_BIG]; 

using namespace std; 

void sieve(int sect[], int n) { 

	for (unsigned int c=2; c<n+1; c++) { 
		sect[c] = c; 
	}
	sect[1] = 0;

	int i=2; 
	int j;
	while(i <= sqrt(n)) {
	
		j = 2;	
		if (sect[i] != 0) 
		{
			while (i*j <= n) { 
				sect[i*j] = 0; 
				j++; 
			}
		}
		
		i++;
	}

}

int main(int argc, char** argv) { 
	int a;
	a = atoi(argv[1]); 
	sieve(arr, a); 
	
	for (int k=2; k<a+1; k++) {
		
		if(arr[k] != 0)
		{
			cout<<arr[k]<<endl; 
		}
	}
	
	return 0; 
}


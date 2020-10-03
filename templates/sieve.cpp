#include<stdio.h> 
#include<vector> 

#define MAXS 10000000

using namespace std; 

bool chk[MAXS]; 

vector<int> divs; 

void sieve(int num) { // returns prime factor using erathostenes sieve?
	int dum; 
	
	for(int i=2; i*i<num; i++) { 
		if ( !chk[i] && num%i == 0) { // if hasn't been checked and it is divisible
			dum = i; 

			divs.push_back(i); 
			while ( dum <= num ) { 
				chk[dum] = true; 
				dum += i; 
			}	
		}
	}	
}

int main() {
	int num; 

	scanf("%d",&num); 

	sieve(num); 

	for(int el : divs ) printf("%d ",el ); 
	printf("\n"); 
}

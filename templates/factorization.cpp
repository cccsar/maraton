#include<stdio.h> 
#include<vector> 
#include<utility> 

using namespace std ;

typedef pair<int, int> pi; 

vector<pi> mults; 

void primefact(int num) { 
	int dum, el = num , acc; 

	for(int i=2; i*i<num; i++) // stop when reaching roof for square root
		if (  el%i == 0 ) {
			dum = i; acc = 0 ; 
			while ( el%dum == 0 ) { // increase power each time the remaining number is still divisible
				el /=dum; 
				acc +=1; 
			}
			mults.push_back( { i, acc } ); 
		}
}

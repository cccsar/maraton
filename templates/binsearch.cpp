#include<stdio.h> 

#define MAXS 10000000

using namespace std ;

int arr[MAXS]; 

bool bs(int el, int f, int c) { 
	int ind =f + (c-f)/2; // choose middle propperly

	if (c >= f) { 

		// in any case, search in subarr that excludes ind
		if ( el < arr[ind] ) 
			return bs(el, f, ind - 1 );  
		else { 
			if ( el == arr[ind] ) 
				return true; 
			return bs(el, ind + 1, c); 
		}
	}

	return false; 
}

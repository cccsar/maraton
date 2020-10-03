#include<stdio.h> 
#include<vector> 
#include<utility> 

using namespace std; 

long long binexp(pair<int, int> power) { 

	if ( power.second == 0) 
		return 1; 

	pair<int, int> cc = { power.first, power.second/2 }; 
	if ( power.second % 2 == 0) 
		return binexp( cc ) * binexp( cc  ); 
	else 
		return binexp( cc ) * binexp( cc ) * power.first; 
}

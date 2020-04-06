#include<stdio.h> 
#include<algorithm> 

const int ALPHAS = 10; 

char let[ALPHAS] ; 
int main() { 
	
	for(int i=0; i<ALPHAS; i++) let[i] = 97 + i; 

	printf("%s\n",let); 
	while ( std::next_permutation(let, let+ALPHAS) )  
		printf("%s\n",let); 
	
}

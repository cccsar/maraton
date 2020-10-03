#include<iostream> 
#include<stdio.h> 

#define MAXS 10000
	
using namespace std; 

int monster[MAXS]; 
long long resp[MAXS]; 

long long farida(int ind)
{
	if (ind == 0)
		return monster[0];
	else if (ind == 1)
		return max(monster[1], monster[0]); 
	else 
		return max( farida(ind - 2) + monster[ind], farida(ind - 1) );  
}	

int main() {
	int t, n; 

	scanf("%d",&t); 

	for (int c=0; c<t; c++) {
		scanf("%d",&n); 
		for(int r=0; r<n; r++)  
			scanf("%d",&monster[r]);

		resp[c] = farida(n-1); 
	}

	for (int k=0; k<t; k++) printf("Case %d: %lld\n",k+1, resp[k]); 
}

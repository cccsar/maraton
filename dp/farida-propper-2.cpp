#include<iostream> 

	
using namespace std; 

long long farida(int coins[], int ind); 

int main() 
{
	int t; 

	cin>>t; 
	long long resp[t]; 

	int aux, n; 
	int monster[10000]; 
	for (int c=0; c<t; c++) {

		cin>>n; 
		for(int r=0; r<n; r++) { 
			cin>>aux; 
			monster[r] = aux; 
		}

		resp[c] = farida(monster, n-1); 

	}

	for (int k=0; k<t; k++)  
		cout<<"Case "<<k+1<<": "<<resp[k]<<endl; 
	return 0; 
}

long long farida(int coins[], int ind)
{
	if (ind == 0)
		return coins[0];
	else if (ind == 1)
		return max(coins[1], coins[0]); 
	else 
		return max( farida(coins, ind - 2) + coins[ind], farida(coins, ind - 1) );  
}	

#include<iostream> 
	
using namespace std; 

long long farida(int coins[], long long c_case[], int ind); 

int main() 
{
	int t; 

	cin>>t; 
	long long resp[t]; 

	int aux, n; 
	int monster[10000]; 
	long long help[10000]; 
	for (int c=0; c<t; c++) { 

		cin>>n; 
		for(int r=0; r<n; r++) { 
			cin>>aux; 
			monster[r] = aux; 
			help[r] = -1; 
		}

		resp[c] = farida(monster, help, n-1 ) ; 

	}

	for (int k=0; k<t; k++) { 
		cout<<"Case "<<k+1<<": "<<resp[k]<<endl; 
	}
			
	return 0; 
}

long long farida(int coins[], long long c_case[], int ind)
{

	if (ind == 0)
		return coins[0]; 

	else if (ind == 1)
		return max(coins[0], coins[1]); 

	else { 
		if (c_case[ind] == -1)
			c_case[ind] = max( farida(coins, c_case, ind - 2) + coins[ind], farida(coins, c_case, ind - 1) ); 

		return c_case[ind]; 
	}

}

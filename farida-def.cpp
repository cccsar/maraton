#include<iostream> 
	
using namespace std; 

int farida(int coins[], int c_case[], int size, int ind); 

int main() 
{
	int t;

	cin>>t; 
	int resp[t]; 

	int aux, n;
	for (int c=0; c<t; c++) { 

		cin>>n; 
		int monster[n], help[n]; 
		for(int r=0; r<n; r++) { 
			cin>>aux; 
			monster[r] = aux; 
			help[r] = -1; 
		}

		if ( n > 1 ) 
		{	
			resp[c] = farida(monster, help, n, n + 1); 
		}
		else { 
			resp[c] = farida(monster, help, n, n-1); 
		}
	}

	for(int k=0; k<t; k++) { 
		cout<<"Case "<<k+1<<": "<<resp[k]<<endl; 
	}

	return 0; 
}

int farida(int coins[], int c_case[], int size, int ind) 
{

	if (ind == 0)
	{
		return coins[0];
	}
	else if (ind == 1)
	{
		return (coins[1] > coins[0])? coins[1]: coins[0];
	}
	else if (ind == 2)
	{
		return (coins[2] + coins[0] > coins[1])? coins[2] + coins[0] : coins[1];
	}
	else  {
		if (c_case[ind - 2] == -1) 
		{
			c_case[ind-2] = farida(coins, c_case, size, ind-2); 
		}

		if (c_case[ind - 3] == -1) 
		{
			c_case[ind-3] = farida(coins, c_case,size, ind-3); 
		}

		if ( c_case[ind-2] > c_case[ind-3] )
		{
			if (ind > size) 
			{
				return c_case[ind-2]; 
			}

			return coins[ind] + c_case[ind-2]; 
		}
		else { 
			if (ind > size)
			{
				return c_case[ind-3]; 
			}

			return coins[ind] + c_case[ind-3]; 
		}

	}


}

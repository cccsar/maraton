#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

int farida(int coins[], int size, int ind);  

/*
 * This program only draws the recursive solution without using any help to avoid overlapping problems.
 *
 */
int main() 
{
	int t; 

	cin>>t; 
	int resp[t]; 

	int n, aux; 
	for (int c=0; c<t; c++) { 
		cin>>n;

		int monster[n];  
		for(int r=0; r<n; r++) { 
			cin>>aux; 
			monster[r] = aux; 
		}

		resp[c]  = farida(monster, n, n + 1); 
	}

	for(int i=0; i<t; i++) { 
		cout<<"Case "<<i+1<<": "<<resp[i]<<endl; 
	}

	return 0; 
}

int farida(int coins[], int size, int ind) 
{
	int first, second; 
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
		return (coins[2] + coins[0] > coins[1])? coins[2] + coins[0]: coins[1];
	}
	else 
	{
		first = farida(coins, size, ind-2); 
		
		second = farida(coins, size, ind-3); 

		if (first > second ) 
		{
			if (ind > size)
			{
				return first ;
			}
			return first + coins[ind]; 
		}
		else { 
			if (ind > size)
			{
				return second;  
			}
			return second + coins[ind]; 
		}
	}

		
}


#include<iostream> 
#include<stdio.h> 
#include<string> 
#include<bitset> 
	
using namespace std; 

void rec_rev(int coins[], bool bits[], int ind); 
int sum_bits(int coins[], bool bits[], int size); 

int main() 
{
	int monster[10001];
	int t; 
	cin>>t; 
	
	int resp[t]; 

	int n, aux, prev, current; 
	bool cond; 
	for(int i=0; i<t; i++) { 

		cin>>n; 	
		for(int j=0; j<n; j++) { 
			cin>>aux; 
			monster[j] = aux; 
		}
	
		bool acum[n]; 
		acum[0] = 1; 
		for(int c=1; c<n; c++) { 
			
			rec_rev(monster, acum, c);
		}		

		resp[i] = sum_bits(monster, acum, n);  
			
	}
			
	for(int k=0; k<t; k++) { 
		cout<<"Case "<<k+1<<": "<<resp[k]<<endl; 
	}


	return 0; 
}

void rec_rev(int coins[], bool chosen[], int ind) 
{
	int r_p, l_p;
	if (ind >= 1)
	{
		if (chosen[ind-1]) 
		{
			r_p = coins[ind]; 
			if (ind >= 2)
			{
				l_p = coins[ind-1]; 

				if (l_p + r_p > coins[ind])
				{
					chosen[ind-1] = false; 
					chosen[ind-2] = true; 
					rec_rev(coins, chosen, ind-2); 
				}
				else { 
					chosen[ind] = false; 
				}
			}
			else if (ind == 1) {
				if (r_p > coins[ind-1])
				{
					chosen[ind-1] = false; 
					chosen[ind] = true; 
				}
			}
		}
		else { 
			chosen[ind] = true; 
		}
	}

}

int sum_bits(int coins[], bool bits[], int size) 
{
	int response = 0; 

	for (int k=0; k<size; k++) { 
		if ( bits[k] )
		{
			response += coins[k]; 
		}	
	}
	
	return response; 
}

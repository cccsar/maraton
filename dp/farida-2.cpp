#include<iostream> 
#include<string> 
	
using namespace std; 

void rec_rev(int coins[], bool chosen[], int ind);
int bits_sum(int coins[], bool chosen[], int size); 

int main() 
{
	int t;
	cin>>t; 
	int resp[t]; 

	int n, aux; 
	for(int c=0; c<t; c++) { 

		cin>>n; 
		int monster[n]; 
		bool chosen[n]; 
		for(int r=0; r<n; r++) { 
			cin>>aux; 
			monster[r] = aux; 
			chosen[r] = 0;
		}
		
		chosen[0] = 1; 
		for(int i=1; i<n; i++) {

			if (chosen[i-1])
			{
				if (monster[i-1] < monster[i])
				{
					chosen[i-1] = 0; 
					chosen[i] = 1; 
					rec_rev(monster, chosen, i-2); 		
				}
			}
			else { 
				chosen[i] = 1; 
			}	
		}	

		resp[c] = bits_sum(monster, chosen, n); 
	}

	for(int j=0; j<t; j++) { 
		cout<<"Case "<<j+1<<": "<<resp[j]<<endl; 
	}

	return 0; 
}

void rec_rev(int coins[], bool chosen[], int ind)
{
	if (ind >= 1)
	{
		if (chosen[ind]==0 && chosen[ind-1]==0)
		{
			chosen[ind] = 1; 
		}
		else if (chosen[ind-1]==1 && chosen[ind]==0)
		{
			if (coins[ind] > coins[ind-1])
			{
				chosen[ind-1] = 0; 
				chosen[ind] = 1; 
				rec_rev(coins, chosen, ind-2); 
			}
			
		}
	}
	else if (ind==0)
	{
		chosen[ind] = 1; 
	}

}

int bits_sum(int coins[], bool chosen[], int size) 
{
	int acum = 0; 

	for(int i=0; i<size; i++) { 
		if (chosen[i]) { 
			acum += coins[i]; 
		}
	}
	return acum; 

}

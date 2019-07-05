
#include<iostream> 
#include<string> 
#include<math.h>
#include<queue>
	
using namespace std; 

queue<int> sieveModif(int n, int l_bound); 

int main() 
{
	int t;
	cin>>t; 
	queue<int> resp[t]; 	// it is either this array (whose allocation i'm unable to calculate yet)
	long a, b;

	for (int i=0; i<t; i++) {
		cin>>a; 
		cin>>b; 
		resp[i]  = sieveModif(b, a);
	}
		 
	for (int j=0; j<t; j++) {
		
		while( !resp[j].empty() )
		{
			cout<<resp[j].front()<<endl; 
			resp[j].pop(); 
		}	
	
		if (j != t-1) 
		{
			cout<<endl; 	
		}
	}

	return 0; 
}

queue<int> sieveModif(int n, int l_bound){ 
	
	queue<int> primes; 
	int arr[n+1];

	for (int i=0; i<n+1; i++) {
		arr[i] = i; 	
	}
	
	arr[0] = arr[1] = -1; 

	int j = 2;
	while (	j <= sqrt(n) ) { 

		int k = 2; 
		while ( j*k <= n ) { 
			arr[j*k] = -1; 
			k++; 
		}
		
		j++;
	}

	for (int l=l_bound; l<n+1; l++) { 
		
		if (arr[l] != -1) 
			{
				primes.push(arr[l]);				
			}
	}
	
	return primes;
}

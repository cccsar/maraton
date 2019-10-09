
#include<iostream> 
#include<string> 
#include<math.h>
#include<bitset>
#include<vector>
#include<iterator>
	
using namespace std; 

vector<unsigned int> sieveModif(long n, long l_bound); 

int main() 
{
	int t;
	cin>>t; 
	vector<unsigned int> resp[t]; 	

	long a, b;
	for (int i=0; i<t; i++) {
		cin>>a; 
		cin>>b; 
		resp[i]  = sieveModif(b, a);
	}
		 

	for (int j=0; j<t; j++) {
		
		for (vector<unsigned int>::iterator it = resp[j].begin(); it!=resp[j].end(); it++) 
		{
			cout<<*it<<endl; 
		}	
	
		if (j != t-1) 
		{
			cout<<endl; 	
		}
	}

	return 0; 
}

vector<unsigned int> sieveModif(long n, long l_bound){ 
	
	bitset<1000000001> bithelp; 
	vector<unsigned int> primes; 
	primes.resize(n-l_bound+1); 

	bithelp[0] = bithelp[1] = 1; 

	int j = 2;
	while (	j <= sqrt(n) ) { 

		int k = 2; 
		if (bithelp[j] != 1)
		{
			while ( j*k <= n ) { 
				bithelp[j*k] = 1; 
				k++; 
			}
		}		
		j++;
	}

	for (unsigned int l=l_bound; l<n+1; l++) { 
		
		if (bithelp[l] != 1) 
			{
				primes.push_back(l); 				
			}
	}
	
	return primes; 
}

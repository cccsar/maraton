#include<iostream> 
	
using namespace std; 

#define MAX_ARR_SIZE 100

int t, st[MAX_ARR_SIZE], in[MAX_ARR_SIZE], ex[MAX_ARR_SIZE], resp[MAX_ARR_SIZE];

int main() 
{
	cin>>t; 
	int i;
	for (i=0; i<t; i++) 
		cin>>st[i]>>in[i]>>ex[i];

	int j, a, b, count; 
	for (j=0; j<t; j++) {
	
		count = 0; 
		a = st[j] + ex[j]; 
		b = in[j] ;
		while (a>in[j] && b<st[j]+ex[j] && a>b) {
			a--;
			b++;
			count++; 
		}

		resp[j] = count; 
	}

	int k; 
	for(k=0; k<t; k++) 
		cout<<resp[k]<<endl; 

	return 0; 
}

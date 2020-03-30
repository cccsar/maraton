#include<math.h> 
#include<stdio.h> 

const int MAXX = 100; 

int resp[MAXX], arr[MAXX]; 

int main() { 
	int i, j, n, q, acum; 

	scanf("%d",&q); 
	
	for (i = 0; i<q; i++) { 
		acum = 0; 

		scanf("%d",&n); 

		for (j=0; j<n; j++)   {
			scanf("%d",&arr[j]); 
			acum += arr[j]; 
		}

		resp[i] = ceil( (float) acum / n ); 
	}

	for ( i=0; i<q; i++) 
		printf("%d\n",resp[i]); 

	return 0 ;
}

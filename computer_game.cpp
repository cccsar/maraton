#include<stdio.h> 

const int MAXR = 100000;

int resp[MAXR] ; 

int main () { 
	int q, k, n, a, b; 

	scanf("%d", &q); 

	for(int i=0; i<q; i++) { 
		scanf("%d %d %d %d", &k, &n, &a, &b); 

		if ( k > a ) { 
			int diff, imp, rem; 

			diff = k-b ; 
			imp = k/a; 

			while(imp >= 0) { 
				rem = (k - a*imp)/b; 
				if ( imp + rem >= n ) 
					break; 

				imp -= 1; 
			}

			resp[i] = (imp < 0)? -1: imp ; 
		}
		else 
			resp[i] = -1; 
	}

	for(int j=0; j<q; j++) printf("%d\n",resp[j]); 
}

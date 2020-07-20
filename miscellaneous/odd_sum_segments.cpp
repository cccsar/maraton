#include<stdio.h>

const int MAXX = 200000;

int help[MAXX];
bool imp[MAXX];
int resp[MAXX][MAXX];

int main() {
	int q, n, k, run, numodd, curr;

	scanf("%d",&q);

	for(int i=0;i<q;i++){
		scanf("%d %d", &n, &k);
		
		run = 0;
		numodd = 0;

		for(int j=0; j<n; j++) {
	              	scanf("%d", &curr);

			run += curr;
			if ( curr%2 ) { 
				imp[j] = true;
				numodd += 1;
			}
		}

		if ( (run%2==0 && k%2==1 ) || (run%2==1 && k%2==0) || (numodd < k) ) //break conditions
                	resp[i][0] = -1;
		else {
			int aiud = numodd, it=0;
			while (aiud > k) {
					
			}		
		}


		for(int j=0;j<n; j++) help[j] = false;
	}
}

#include<stdio.h>
#include<utility> 
#include<algorithm> 

using namespace std; 

typedef pair<int, int> ii; 

const int MAXT = 100;
const int MAXN = 1000; 

char resp[MAXT][MAXN + 1]; 
ii *help = new ii[MAXN*2]; 

int main() { 
	int T, N; 

	scanf("%d",&T); 

	for (int i=0; i<T; i++) { 
		scanf("%d", &N); 
		int a,b; 
		for (int j=0; j<2*N; j+=2) { 
			scanf("%d %d",&a, &b); 
			help[j] = { a, j/2 }; 
			help[j+1]  = { b, j/2 }; 
		}
		sort(help, help+2*N); 
		
		for (int j=0; j<2*N; j++) 
			printf("%d %d\n",help[j].first, help[j].second); 

		for (int j=0; j<2*N; j++) { 
			if ( help[j].second != help[j+1].second ) { 
				
			}
		}	
	}


}

#include<stdio.h> 

#define MIN(a,b) (a>b)? b: a

const int MAXT = 10000; 
const int MAXN = 150000; 
const int BIG = 0x7fffffff;

int resp[MAXT+1];
int prices[MAXN+1] ; 

int main() { 
	int N,T, acum; 

	scanf("%d",&T); 

	
	for (int i=0; i<T; i++) { 
		acum = 0; 
		scanf("%d",&N); 
		for (int j=0; j<N; j++)  scanf("%d", &prices[j]); 

		int temp = BIG ; 
		for (int j=N-1; j>=0; j--) {
			temp = MIN(prices[j], temp); 
			acum += (prices[j]>temp)? 1: 0; 
		}

		resp[i] = acum; 
	}

	for (int i=0; i<T; i++) printf("%d\n",resp[i]); 
}


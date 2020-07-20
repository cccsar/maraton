#include <stdio.h>
#include <cmath>

const int MAXQ = 1000;

long long resp[MAXQ + 1]; 

int main() { 
	int q;
	long long a, b ,c ;
	scanf("%d",&q);

	for(int i=0; i<q;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		resp[i] =  (a + b + c) / 2 ;
	}

	for(int j=0; j<q; j++) printf("%lld\n",resp[j]);

}

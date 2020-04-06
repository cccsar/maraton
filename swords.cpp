#include<stdio.h> 
#include<algorithm> 

using namespace std; 

const int MAXX = 200000; 

int arr[MAXX], diff[MAXX]; 

int gcd(int a, int b) { 
	int mx = max(a,b), mn = min

}

int main() { 
	int N; 

	scanf("%d",&N);
	int mx = -1; 
	for (int i=0; i<N; i++) { 
		scanf("%d",&arr[i]); 
		mx = max(mx, arr[i]); 
	}	

	int acc = 0;
	for (int j=0; j<N; j++)  {
		diff[j] = mx - arr[j]; 
		acc += diff[j]; 
	}
	int imp = gcd(acc, mx); 
	if ( imp == 1 ) 
		printf("%d %d\n", imp, N); 
	else {
		int mn = 1000000000;
		for (int k=0; k<N-1; k++) mn = min(mn, gcd(imp, diff[k])); 
		printf("%d %d",mn, acc/mn); 
	}
	
}


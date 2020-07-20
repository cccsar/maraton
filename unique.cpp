#include <stdio.h>
#include <algorithm>

const int SOMEMAX = 500; 

int arr[SOMEMAX]; 

int main() { 
	int N; 

	scanf("%d",&N); 

	for(int i=0; i<N; i++) scanf("%d",&arr[i]); 

	std::sort(arr,arr+N); 

	printf("%d ",arr[0]); 
	for(int j=0; j<N-1; j++) 
		if ( arr[j] != arr[j+1] ) printf("%d ",arr[j+1] ); 
	printf("\n"); 

}


#include<stdio.h> 

const int MAXX = 200; 

bool resp[MAXX + 1] ; 
int arr[MAXX + 1] ; 

int main(){ 
	int n, q ;

	scanf("%d",&q); 

	for (int i=0; i<q; i++) { 
		scanf("%d",&n); 

		for (int j=0; j<n; j++) scanf("%d",&arr[j]); 

		bool a, b; 
		a = b = true; 
		int j; 
		for (j=1; j<n ;j++) { 
			if ( (arr[j-1] == arr[j]+1  || (arr[j-1] == 1 && arr[j] == n)) && a )  //decreasing
				b = false; 
			else if ( (arr[j-1]+1 == arr[j] || (arr[j-1] == n && arr[j] == 1) ) && b )  //increasing
				a = false; 
			else 
				break; 
		}	

		resp[i] = (j == n)? true: false; 
	}

	for (int i=0; i<q ;i++) (resp[i])? printf("YES\n"): printf("NO\n"); 
}

#include<stdio.h> 

int main() {
	int n, acc, help, c = 1; 

	while (scanf("%d",&n), n != 0 ) { 
		acc = 0;
		
		while (n--) { 
			scanf("%d",&help); 
			acc += (help >= 1)? 1 : -1; 
		}
	
		printf("Case %d: %d\n", c, acc); 
		c+=1; 
	}
}

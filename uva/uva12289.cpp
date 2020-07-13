#include <stdio.h> 
#include <string.h>

const int SIZE = 7; 
const char * ONE = "one"; 
const char * TWO = "two";

int main() {
	char word[SIZE]; 
	short int n, acc, cca; 

	scanf("%hd",&n); 

	while (n--) {
		scanf("%s",word); 
		if ( strlen(word) == 5 ) printf("3\n"); 
		else { 
			acc = 0; 
			for(int i=0; i<3; i++) 
				if ( word[i] == ONE[i] ) acc += 1 ;
					
			printf("%d\n", (acc >= 2)? 1 : 2); 
		}
			
	}
}

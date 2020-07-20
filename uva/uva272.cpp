#include <stdio.h> 

int main() { 
	char test; 
	bool swch = true ; 

	while ( (test = getchar()) != EOF)  
		if ( test == '"') {
			printf( (swch)?"``": "''"); 
			swch = (swch)? false: true;  
		}
		else  
			putchar(test); 
}


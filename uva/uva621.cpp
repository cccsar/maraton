#include <stdio.h> 
#include <string.h>

#define MAXS 10000
#define YAG 3 


char resp[MAXS]; 

const char* corresp = "-*?"; 

char check( char wd[MAXS] ) { 

	int imp[YAG]; 

	int sz = strlen(wd); 

	if ( sz < 3 ) 
		return '+' ;
        else { 
	 	for (int i=0; i<YAG; i++) imp[i] = 0; 	

		imp[0] = (wd[sz-2] = '3' && wd[sz-1] == '5')? 1 : 0; 
		imp[1] = (wd[0] = '9' && wd[sz-1] == '4')? 1: 0 ; 
		imp[2] = (wd[0] = '1' && wd[1] == '9' && wd[2] == '0' )? 1 : 0 ; 

		if ( imp[0] + imp[1] + imp[2] == 1) { 
			if (imp[0] == 1) 
				return corresp[0];  
			if (imp[1] == 1) 
				return corresp[1];  
			if (imp[2] == 1) 
				return corresp[2];  
		}
		else  
			// check first for possible occurrences of positive results
			for (int j=0; j<sz; j++) {  
				if ( wd[j] == '1'  || wd[j] == '4')
					return '+'; 
				if (j != sz) 
					if( wd[j] == '7' && wd[j+1] == '8') // trailing
						return '+'; 
			}

			// check then for remaining possible ocurrences in corresp order
			for (int i=0; i<YAG ; i++)  {
				if ( imp[i] == 1) 
					return corresp[i] ; 
			}
	}	

	return '#';
}

int main () { 
	int n; 
	char wd[MAXS];

	scanf("%d",&n); 

	for (int i=0; i<n; i++) { 
		scanf("%s",wd); 	
		resp[i] = check(wd); 
	}

	for (int i=0; i<n; i++) 
		printf("%c\n",resp[i]) ; 
}

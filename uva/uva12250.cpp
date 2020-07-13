#include <stdio.h> 
#include <string.h> 

const int MAX = 15; 

int main() { 
	int c = 1;
	char country[MAX]; 

	while( scanf("%s",country), strcmp(country,"#") != 0){ 
		printf("Case %d: ",c); 
		if ( !strcmp(country,"HOLA")) printf("SPANISH\n"); 
		else if ( !strcmp(country, "HELLO") ) printf("ENGLISH\n");
		else if ( !strcmp(country, "HALLO") ) printf("GERMAN\n");
		else if ( !strcmp(country, "BONJOUR") ) printf("FRENCH\n");
		else if ( !strcmp(country, "CIAO") ) printf("ITALIAN\n");
		else if ( !strcmp(country, "ZDRAVSTVUJTE") ) printf("RUSSIAN\n");
		else printf("UNKNOWN\n"); 
		c+=1; 
	}

}

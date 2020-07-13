#include <stdio.h> 
#include <unistd.h> // cstuff 
#include <iostream>
#include <string.h> 

const char * one = "one";

int main() { 
	char hola[5]; 

	scanf("%s",hola); 
	printf("%d\n",strcmp(hola, one)); 
}

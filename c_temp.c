#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/wait.h>
#include <fcntl.h>  
#include <dirent.h> 
#include <string.h> 
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SOMETHING 10

void foo(int *a) { 
	printf("%p\n",a); 
}

int main (int argc, char **argv) { 
	int *perro; 

	perro = (int*) malloc (sizeof( int) ); 
	printf("%p \n",perro); 
	
	perro = (int*) realloc( perro, sizeof(int) * 100000); 
	printf("%p \n",perro); 


	return 0; 
}


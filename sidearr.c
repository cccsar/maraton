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
#define MAXEDGES 1000
#define HELP 100
#define NONE -1

int sidearr[2][MAXEDGES];

// Se asume que -1 es un valor no valido de vertice
void init (int m) {
	int i_; 	
		
	for (i_= 0; i_<m ; i_++) { 
		sidearr[0][i_] = NONE; 
		sidearr[1][i_] = NONE; 
	}
}


void create (int m) { 
	int i_, u, v, count; 
	
	count = 0; 
	for (i_= 0; i_<m ; i_++) { 
		scanf("%d %d", &u, &v); 

		sidearr[0][count] = u; 
		sidearr[1][count] = v; 
		count ++ ;
	}

}


void print(int m) { 
	int i_; 

	for (i_= 0; i_<m ; i_++) { 
		printf("edge %d: ", i_); 
		printf("%d ", sidearr[0][i_] ) ;
		printf("%d \n", sidearr[1][i_] ) ;
	}
}

// Implementacion con estructura estatica asume tamano maximo, si se usasen
// arreglos dinamicos habria que hacer realloc cada vez que se inserte un arco
void addEdge(int *m) { 
	int u, v; 

	scanf("%d %d", &u, &v); 
	sidearr[0][*m] = u; 
	sidearr[1][*m] = v; 

	*m += 1; 
}


int nEdges(int m) {
	return m; 	
}


//auxiliar 
// para contar el numero de vertices
int search(int *arr, int e, int *size) { 
	int i_; 

	for (i_= 0 ; i_< *size ; i_++) { 

		if ( e == arr[i_] )
			return TRUE ;
	}
	
	return FALSE; 
}


//Auxiliar
//	para contar el numero de vertices .. se puede mejorar
void append(int *arr, int e, int *size) { 
	arr[ *size ] = e; 
	*size += 1; 
}


//Se implementa esta funcion por asumir que no es necesario saber 
//el numero de vertices para esta DE
int nVertex(int m) { 
	int count, *found , fcurrent, scurrent , i_;  

	found = (int*) malloc( HELP * sizeof(int)  ) ;
	count = 0; 

	for (i_= 0 ; i_< m ; i_++) {  //O(m)
		fcurrent = search( found, sidearr[0][i_], &count) ; 
		scurrent = search( found, sidearr[1][i_], &count) ; 

		if ( fcurrent == FALSE ) 
			append(found, sidearr[0][i_], &count);  // O(k)

		if ( scurrent == FALSE ) 
			append(found, sidearr[0][i_], &count);  //O(k)

	}

	for (i_= 0 ; i_<count ; i_++) { 
		printf("%d ",found[i_]); 
	}
	printf("\n");

	return count; 
}


int main (int argc, char **argv) { 
	int n, m, i_; 

	scanf("%d %d", &n, &m); 

	init(m); 

	create(m); 

	print(m); 

	printf("number of edges: %d\n", nEdges(m)); 

	printf("Anadiendo edges: \n"); 

	addEdge(&m); 

	print(m); 
	
	printf("%d \n", nVertex(m)) ; 

	return 0; 
}


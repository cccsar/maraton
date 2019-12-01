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

#define SOFT_L 16
#define HARD_L 1024 
#define WORD_L 30
#define ALPHA_SIZE 27//10
#define TEST_SIZE 5

/* Dependiendo del tipo de diccionario, se escoge un ascii sobre el que
 * trabajar:
 * 	numeros: 48 - 57
 * 	letras: 97 - 123
 */	

typedef struct {
	int first, second; 
} pair; 

typedef struct trie_node{ 
	struct trie_node *sons[ALPHA_SIZE]; 
	int flag; 
} node; 

typedef struct {
	node root; 
	int size; 
	int n_words; 
} trie;


/* Regresa un entero que representa el caracter ascii asociado con 
 * la letra indexada en i_ para la palabra "number" */
int parseChar(char* number, int i_) { 
	/* Se asume que la entrada esta entre 48 - 57 (digitos [0-9]) */
	//return (int)number[i_] % 48;
	return (int)number[i_] % 97;
}


/* Constructor nodo */
void nodeInit(node *word){ 
	int i_; 
	for(i_=0; i_<ALPHA_SIZE; i_++) 
		word->sons[i_] = -1; 

	word->flag = FALSE; 
}

/* Constructor trie */
void trieInit(trie *tree) { 
	nodeInit( tree->root );

	tree->size = 1 ;
	tree->n_words = 0;
	tree->capacity = SOFT_L; 
}
	

int trieContains(trie *tree, char *word) { 
	int word_size, i_, digit; 
	node dummie; 

	dummie = tree->root ;
	word_size = strlen(word); 
	for(i_=0; i_<word_size; i_++){ 
		
		digit = parseChar(word, i_); 

		if ( dummie.sons[digit] != -1) 
			dummie = *(dummie.sons[digit]);
		else
			break; 
	}

	if( i_ == word_size && dummie.flag == TRUE ) 
		return TRUE; 
	else
		return FALSE; 

}


int trieInsert(trie *tree, char *number ) { 
	int i_, word_size, digit; 
	node *current; 

	word_size = strlen(number);

	printf("Previous address %p\n",tree->root); 
	current = &(tree->root[0]); 
	for(i_=0; i_<word_size; i_++) {

		digit = parseChar(number,i_);

		/* Adjust capacity */
		if (tree->size == tree->capacity)  {

			if( !trieResize(tree) ) {
				fprintf(stderr,"Unable to complete insertion\n");
				return -1;  //### add error correct
			} 
			printf("New address %p\n",tree->root); 
		}

		/* check if ith letter is already saved */
		if( current->sons[ digit ] == -1 ) {
			node dummie; 
			nodeInit(&dummie); 

			printf("Inserting letter %c\n",digit+97);
			tree->root[tree->size ] = dummie;
			current->sons[ digit ] = tree->size ; 

			tree->size++; 
		}
		else {
			if( i_ == word_size-1 ) {
				printf("Already inserted\n");
				return -2;  //### add error correct
			}
		}

		current = &( tree->root[ current->sons[digit] ] ) ; 
	}

	current->flag = TRUE; 
	printf("trie current capacity %d\n",tree->capacity);
}

void trieDfsRec(pair *visited, int size) {
	int i_, j_, k_, counter;
	int word[HARD_L];

	for(i_=0; i_<size; i_++) {

		k_ = i_;
		counter=0;
		while( visited[k_].first != k_ ) {
			word[counter] = visited[k_].second; 
			k_ = visited[k_].first;
			counter++;
		}
		
		if(counter > 0) {
			for(j_ = counter-1; j_ >= 0; j_--)   
				printf("%c",word[j_]+97);
		}
		printf("\n");
		
	}

}


/* Requires an array of int initiallized in -1, a trie, the current node and its index */
void trieDfs (trie *tree, pair *visited, int this, node *dummie) {
	int i_, index; 

	for(i_=0; i_<ALPHA_SIZE ; i_++) { 

		if (dummie->sons[i_] != -1) {
			index = dummie->sons[i_];

			if(visited[ index ].first == -1) {
				visited[ index ].first = this;
				visited[ index ].second = i_;
				trieDfs(tree, visited, index, &tree->root[ index ] );
			}
		}
	}

}


int main(int argc, char **argv) 
{
	char word[WORD_L]; 
	int i_;
	pair *visited;
	trie castano; 

	/* Construct trie */
	trieInit(&castano); 


	/* Read TEST_SIZE input words */
	for(i_=0; i_<TEST_SIZE; i_++) { 
		scanf("%s",word); 
		trieInsert(&castano, word); 
	}


	/* Testing contains */
	for(i_=0; i_<TEST_SIZE; i_++) {
		scanf("%s",word); 
		if( trieContains(&castano, word) ) 
			printf("Found word\n");
	}


	/* Allocate space for visited array) */
	visited = (pair*) malloc( castano.size * sizeof(pair));
	for(i_=0; i_<castano.size; i_++)  { 
		visited[i_].first = -1;
		visited[i_].second = -1;
	}
	visited[0].first = 0; 

	trieDfs(&castano, visited, 0, &castano.root[0]); 
	trieDfsRec(visited, castano.size);


	/* Destroy trie and free stuff*/
	trieTerm(&castano);
	free(visited);

	return 0; 
}


	/*
	 * DBG for each element of the trie
	for(i_=0; i_<TEST_SIZE; i_++) {
		printf("Looking at index %d of trie\n",i_);
		for(int j_=0; j_<ALPHA_SIZE; j_++) { 
			if(castano.root[i_].sons[j_] != -1 )
				printf("%d ",castano.root[i_].sons[j_]);
		}
		printf("\n");
	}
	*/

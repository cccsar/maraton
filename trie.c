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
#define HARD_L 256
#define WORD_L 30
#define ALPHA_SIZE 10
#define TEST_SIZE 5


typedef struct { 
	int sons[ALPHA_SIZE]; 
	int flag; 
} node; 

typedef struct {
	node *root; 
	int size; 
	int n_words; 
	int capacity; 
} trie;

/* Se asume que la entrada siempre esta entre ascii 48 y 57 */
int parseChar(char* number, int i_) { 
	return (int)number[i_] % 48;
}


/* Constructor nodo */
void node_init(node *word){ 
	int i_; 
	for(i_=0; i_<ALPHA_SIZE; i_++) 
		word->sons[i_] = -1; 

	word->flag = FALSE; 
}

/* Constructor trie */
void trie_init(trie *tree) { 
	tree->root = (node *) malloc(sizeof(node)*SOFT_L);
	tree->size = 1 ;
	tree->n_words = 0;
	tree->capacity = SOFT_L; 

	node first; 
	node_init(&first); 
	tree->root[0] = first ;
}

/* Destructor */
void trie_term(trie *tree) { 
	free(tree->root); 
}

/* Ajustador de tamano */
int trie_resize(trie *tree) {
	
	if( tree->capacity * 2 >= HARD_L ) {
		fprintf(stderr,"Reached maxium capacity\n");
		return FALSE; 
	}
	
	tree->root = (node *) realloc(tree->root, sizeof(node) * 2 * tree->capacity );
	tree->capacity *= 2;

	return TRUE; 
}
	

void trie_insert(trie *tree, char *number ) { 
	int i_, word_size, digit; 
	node *current; 

	word_size = strlen(number);

	current = &tree->root[0]; 
	for(i_=0; i_<word_size; i_++) {

		digit = parseChar(number,i_);

		/* Adjust capacity */
		if (tree->size % SOFT_L == 0)  {

			if( !trie_resize(tree) ) {
				fprintf(stderr,"Unable to complete insertion\n");
				return; 
			} 
		}

		/* check if ith letter is already saved */
		if( current->sons[ digit ] == -1 ) {
			node dummie; 
			node_init(&dummie); 

			tree->root[tree->size + 1] = dummie;
			current->sons[ digit ] = tree->size + 1 ; 

			tree->size++; 
		}

		current = &tree->root[ current->sons[digit] ]; 
	}

	current->flag = TRUE; 
}

void recover_dfs_path(int *visited, int size) {
	int i_, k_;

	for(i_=0; i_<size; i_++) {

		k_ = i_;
		while( visited[k_] != k_ ) {
			printf("%d", visited[k_]);
			k_ = visited[k_];
		}
		printf("\n");
		
	}

}
/* Requires an array of int initiallized in -1, a trie, the current node and its index */
void trie_dfs (trie *tree, int *visited, int this, node *dummie) {
	int i_, index; 

	for(i_=0; i_<ALPHA_SIZE ; i_++) { 

		if (dummie->sons[i_] != -1) {
			index = dummie->sons[i_];

			if(visited[ index ] == -1) {
				visited[ index ] = this;
				printf("this: %d\n",this);
				trie_dfs(tree, visited, index, &tree->root[ index ] );
			}
		}
	}

}

int main(int argc, char **argv) 
{
	char word[WORD_L]; 
	int i_;
	int *visited;
	trie castano; 

	/* Construct trie */
	trie_init(&castano); 


	/* Read 10 input words */
	for(i_=0; i_<TEST_SIZE; i_++) { 
		scanf("%s",word); 
		trie_insert(&castano, word); 
	}

	/* Allocate space for visited array) */
	visited = (int*) malloc( castano.size * sizeof(int));
	for(i_=0; i_<castano.size; i_++) 
		*(visited+i_) = -1;
	*visited = 0; 


	trie_dfs(&castano, visited, 0, &castano.root[0]); 
	recover_dfs_path(visited, castano.size);
	for(i_=0; i_<castano.size; i_++) 
		printf("%d ",*(visited+i_));

	printf("\nSIZE: %d",castano.size);


	/* Destroy trie and free stuff*/
	trie_term(&castano);
	free(visited);

	return 0; 
}


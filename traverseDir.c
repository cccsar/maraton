
#include <stdio.h> 
#include <stdlib.h>
#include<sys/types.h> 
#include<dirent.h> 
/*
void dirPrint(DIR *dir, dirent *ent) { 

	while( (ent=readdir(dir)) != NULL ) { 
		printf("nombre: %s\n",dir_ent->d_name);
		printf("inodo: %ld\n",dir_ent->d_ino);
		printf("offset: %ld\n",dir_ent->d_off);
		printf("record lenght: %d\n",dir_ent->d_reclen);
		printf("type of file: %d\n",dir_ent->d_type);
		printf("\n");
	}
}

//tal vez serviria empilar o encolar los DIR* en una estructura para recorrerlo
void dirTraverse(DIR *dir) { 

	struct dirent *current_ent; 
	DIR *ith_pointer;
	while (true) { 
		if (current_ent->d_type == 4 && current_ent->d_name!='.' && current_ent->d_name!='..'  );
		{ 
			ith_pointer = opendir(current_ent->d_name); //dara problemas por no ser const char
			dirPrint(ith_pointer,
			dirTraverse(ith_pointer); 
		}

			
	}
}
*/
int main (int argc, char **argv) { 
	
	
	DIR *dir;
	struct dirent *dir_ent; 

	if ( (dir=opendir(argv[1])) == NULL ) 
	{
		fprintf(stderr,"error opening directory"); 
		perror("opendir"); 
	}

	while( (dir_ent=readdir(dir)) != NULL ) { 
		printf("nombre: %s\n",dir_ent->d_name);
		printf("inodo: %ld\n",dir_ent->d_ino);
		printf("offset: %ld\n",dir_ent->d_off);
		printf("record lenght: %d\n",dir_ent->d_reclen);
		printf("type of file: %d\n",dir_ent->d_type);
		printf("\n");
	}
	
	closedir(dir); 
		
	exit(0);	
}


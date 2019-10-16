
#include <stdio.h> 
#include <stdlib.h>
#include<sys/types.h> 
#include<dirent.h> 
#include <string.h> 



//tal vez serviria empilar o encolar los DIR* en una estructura para recorrerlo
void dirTraverse(DIR *dir, char *dirname) { 

	struct dirent *current_ent; 
	DIR *ith_pointer;
	char path[256]; 

	strcpy(path,dirname); 

	while( (current_ent=readdir(dir)) != NULL ) { 

		if( strcmp(current_ent->d_name,".")!=0 && strcmp(current_ent->d_name,"..")!=0) 
		{
			printf("nombre: %s\n",current_ent->d_name); 

			if (current_ent->d_type == DT_DIR )  
			{ 
				char current_name[256]; 
				strcat(current_name, path); 

				strcat(path,"/"); 
				strcat(path, current_ent->d_name); 

				printf("%s\n", path); 

				if ((ith_pointer = opendir(path)) == NULL )  
					perror("opendir");

				dirTraverse(ith_pointer, path); 
				strcat(path,current_name); 
			}
		}
	}
	closedir(ith_pointer); 
}
int main (int argc, char **argv) { 
	
	
	DIR *dir;
	struct dirent *entry; 
	char *local_path = (char*) malloc(256*sizeof(char));

	strcpy(local_path, "./"); 
	strcat(local_path, argv[1]); 

	if ( (dir=opendir(local_path)) == NULL ) 
	{
		fprintf(stderr,"error opening directory"); 
		perror("opendir"); 
	}

	dirTraverse(dir, argv[1]); 
	/*
	while( (dir_ent=readdir(dir)) != NULL ) { 
		printf("nombre: %s\n",dir_ent->d_name);
		printf("inodo: %ld\n",dir_ent->d_ino);
		printf("offset: %ld\n",dir_ent->d_off);
		printf("record lenght: %d\n",dir_ent->d_reclen);
		printf("type of file: %d\n",dir_ent->d_type);
		printf("\n");
	}
	*/	
	closedir(dir); 
		
	exit(0);	
}


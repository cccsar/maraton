
#include <stdio.h> 
#include <stdlib.h>
#include<sys/types.h> 
#include<dirent.h> 
#include <string.h> 



void cat(FILE *fd) {
	
	

}
//tal vez serviria empilar o encolar los DIR* en una estructura para recorrerlo
void dirTraverse(DIR *dir, char *dirname) { 

	struct dirent *current_ent; 
	DIR *ith_pointer;
	char path[256]; 

	strcpy(path,dirname); 

	//primer print

	while( (current_ent=readdir(dir)) != NULL ) { 

		if( strcmp(current_ent->d_name,".")!=0 && strcmp(current_ent->d_name,"..")!=0) 
		{
			// primer guardado de path; 
			char first_current_name[256], buffer[256];	//fcn,modificacion de path sobre la marcha
			strcpy(first_current_name, path); 		//temp de fcn
			strcpy(buffer, first_current_name); 

			strcat(first_current_name,"/"); 
			strcat(first_current_name, current_ent->d_name);	//modifico fcn 
			printf("%s\n",first_current_name); 

			if (current_ent->d_type == DT_DIR )  
			{ 
				
				if ((ith_pointer = opendir(first_current_name)) == NULL )  //Cierro directorio	
					perror("opendir");

				dirTraverse(ith_pointer, first_current_name); //esta llamada cambia fcn
				strcpy(first_current_name, buffer);		//esto recupera fcn, con el temp en buffer ;
			}
			
		}
	}
	closedir(ith_pointer); 								//abro directorio
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

	closedir(dir); 
		
	exit(0);	
}


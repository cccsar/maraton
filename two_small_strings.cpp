#include<stdio.h> 
#include<string.h> 

#define MAX(a,b) ((a>b)? a: b)
#define MIN(a,b) ((a<b)? a: b)

const int MAXS = 100000; 
const int LIT = 2; 

char out[3*MAXS + 1], fst[LIT], scd[LIT];  

int main() { 
	int N; 
	
	scanf("%d",&N); 
	scanf("%s\n%s",fst, scd); 

	if (fst[0] != fst[1] && scd[0] != scd[1]) {//not repeated

		if ( fst[0] == scd[1] && fst[1] == scd[0] ) { 
			char let; 

			int num = MAX(fst[0], scd[1]) - MIN(fst[0], scd[1]); 
			if ( num == 1) 
				let = ( MAX(fst[0],scd[1]) == 'c' )? 'a': 'c'; 
			else 
				let = 'b'; 

			for (int i=0; i<N; i++) out[i] = fst[0];  

			for (int j=N; j<3*N; j+=2) { 
				out[j] = let; 
				out[j+1] = fst[1]; 
			}
			//inverted case
		}
		else if ( fst[0] == scd[0] && fst[1] != scd[1]) { 
			for ( int i=0; i<2*N; i+=2) { 
				out[i] = fst[1]; 
				out[i+1] = scd[1]; 
			}
			for (int j=2*N; j<3*N; j++) out[j] = fst[0]; 
			//equal ends case 1

		}
		else if ( fst[1] == scd[1] && fst[0] != scd[0]) { 
			for(int i=0; i<N; i++) out[i] = fst[1]; 
			for(int j=N; j<3*N; j++) { 
				out[j] = fst[0]; 
				out[j+1] = scd[0]; 
			}
			//equal ends case 2
		}
		else if ( (fst[0] == scd[1] && fst[1] != scd[0]) ||
				(fst[1] == scd[0] && fst[0] != scd[1]) ) { 

			for (int i=0; i<3*N; i+=3) { 
				out[i] = (fst[0]==scd[1])? scd[1]: fst[1]; 
				out[i+1] = (fst[0]==scd[1])? scd[0]: fst[0]; 
				out[i+2] = (fst[0]==scd[1])? fst[1]: scd[1];
			}
			//transitive case 1 and 2
		}
		else if ( fst[0] == scd[0] && fst[1] == scd[1] ) {
			printf("lleog\n"); 
			char let; 

			int num = MAX(fst[0],fst[1]) - MIN(fst[0],fst[1]); 

			if ( num == 2 ) 
				let = 'b'; 
			else 
				let = (MAX(fst[0],fst[1]) == 99)? 'a': 'c'; 

			for( int i=0; i<3*N; i+=3) { 
				out[i] = fst[1]; 
				out[i+1] = fst[0]; 
				out[i+2] = let; 
			}
			//equal pairs

		}
	}
	else { //repeated
		if ( fst[0] != fst[1] || scd[0] != scd[1] ) { 
			bool diffst; 

			diffst = ( fst[0] == fst[1] )? true: false; 

			for (int i=0; i<3*N; i+=3) { 
				out[i] = (diffst)? fst[0]: scd[0]; 
				out[i+1] = (diffst)? scd[1]: fst[1]; 
				out[i+2] = (diffst)? scd[0]: fst[0];  

			}
			//at least one different
		}
		else { 
			for (int i=0; i<3*N; i+=3) { 
				out[i] = 'a' ;
				out[i+1] = 'b';  
				out[i+2] = 'c';  
			}
			//both equal
		}

	}


	printf("YES\n"); 
	printf("%s\n",out); 
}

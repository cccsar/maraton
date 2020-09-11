#include <stdio.h> 
#include <utility> 

#define MAXM 100

int resp[MAXM]; 

std::pair<int, float> * depR = new std::pair<int, float> [MAXM] ; 

int main() {
	float dp, loan; 
	int dur = 1, nr, ind = 0; 
	 
	while ( dur > 0) { 
		
		scanf ("%d %f %f %d",&dur, &dp, &loan, &nr); 
		
		int month; 
		float dep ; 
		for (int i=0; i<nr; i++) { 
			scanf ("%d %f", &month, &dep); 
			depR[i] = {month,dep} ;
		}

		int help = -1; 
		float k = loan / dur, tot = dp + loan, remL = loan; 
		for (int i=0; i<dur; i++) { 
			if ( help != nr && i == depR[help+1].first ) 
				help += 1 ; 	

			tot *= (1-depR[help].second) ; 
			remL = loan - k*i ; 

			if ( remL < tot ) { 
				resp[ind] = i ; 
				break; 
			}
				
		}

		ind += 1; 
	}
	

	for (int i=0; i<ind-1 ;i++) 
 		printf("%d %s\n", resp[i], (resp[i] > 1)? "months": "month" ) ;		

}

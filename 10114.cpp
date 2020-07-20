#include<stdio.h>
#include<cmath> 
#include<vector> 
#include<utility> 

using namespace std; 

const int MAXM = 100;
const int MAXC = 1000; 

float current[MAXM] ; 
int resp[MAXC] ; 

int main() { 
	int dur, months, it; 
	float downp, loan;


	for(int j=0; j<MAXM; j++) current[j] = -1; 

	it = 0 ;
	while ( true ) {  
		scanf("%d %f %f %d", &dur, &downp, &loan, &months); 
		if ( dur < 0) break; 

		int help; 
		for(int i=0; i<months; i++) { 
			scanf("%d",&help); 
			scanf("%f",&current[help]); 
		}
		
		
		int cnt = 0; 
		float owed, worth, last;  

		owed = worth = downp + loan; 
		

		while( (owed >= worth) &&  (cnt <= dur) ) {
			last = ( current[cnt] != -1)? current[cnt] : last; 

			owed -= downp; 
			worth *= last; 

			cnt += 1 ;
		}
		
		resp[it] = cnt;  

		for(int j=0; j<dur; j++) current[j] = -1; 
		it += 1; 
	}

	for(int j=0; j<it; j++) 
		(resp[j]>1)? printf("%d months\n", resp[j]) : printf("%d month\n", resp[j]); 

}

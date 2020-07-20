#include <stdio.h>

#define MIN(a,b) (a<b)? a: b

int main() { 
	int N, current; 
	scanf("%d",&N); 

	int ev, od; 
	ev = od = 0 ;
	for (int i=0; i<N ; i++) { 
		scanf("%d", &current); 
		(current%2)? od += 1: ev += 1; 
	}
	printf("%d\n",MIN(ev,od)); 
}

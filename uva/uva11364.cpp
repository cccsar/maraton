#include<stdio.h> 

const int MAXINT = 100; 
const int MININT = -1; 

int main() { 
	int t, n, mm, p, q; 

	scanf("%d", &t) ;

	while ( t--) { 
		p = MAXINT; 
		q = MININT; 

		scanf("%d",&n); 

		while (n--) { 
			scanf("%d",&mm); 
			p = (mm<p)? mm: p; 
			q = (mm>q)? mm: q; 
		}

		printf("%d\n", 2*(q-p)); 
	}
}

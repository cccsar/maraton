#include <stdio.h> 


int main() { 
	int a, b, c, d, help; 	

	while ( scanf("%d %d %d %d",&a, &b, &c, &d), (a || b || c || d) ) { 
		help =  9*((b<a)? 40-a+b: b-a);
		help += 9*((c<b)? b-c: 40-c+b); 
		help += 9*((d<c)? 40-c+d: d-c);

		printf("%d\n",1080 + help); 
	}
}

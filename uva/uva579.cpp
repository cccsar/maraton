#include<stdio.h> 
#include<math.h> 

int main() { 
	float m, h, help; 

	while ( scanf("%f:%f",&h, &m), (m+h!=0) ) { 
		help = abs( fmod(30*h + 30*m/60,360) - 6*m); 
		
		printf("%.3f\n", (help>180)? 360-help: help); 
	}
}

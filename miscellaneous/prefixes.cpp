#include<stdio.h> 
#include<string.h> 

const int MAXX = 200000; 

char word[MAXX+1]; 
int keep[MAXX/2]; 

int main() { 
	int n; 
	scanf("%d",&n); 

	scanf("%s", word); 

	for(int i=1; i<n; i+=2) { 
		if ( word[i] == 'a' )  
			keep[i/2] = (word[i-1]!='a')? 0: 1; 
		else
			keep[i/2] = (word[i-1]!='b')? 0: -1; 
	}
	
	int cnt = 0; 
	for (int j=0; j<n/2; j++) { 
		if ( keep[j] == 1 ) { 
			word[2*j] = 'b'; 
			cnt+=1; 
		}
		else if ( keep[j] == -1) {
			word[2*j] = 'a'; 
			cnt+=1; 
		}
	}
	
	printf("%d\n%s\n",cnt, word); 
}

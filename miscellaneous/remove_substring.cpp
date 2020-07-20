#include<stdio.h> 
#include<string.h> 
#include<vector> 
#include<set> 

#define MAX(a,b) ( (a>b)? a: b )

using namespace std; 

const int MAXS = 2*100; 

bool comp(char *st, char *subs, int a, int size) { 
	for (int i=0; i<size; i++) 
		if ( subs[i] != st[i+a] )	
			return false; 
	return true; 
}

int main() { 
	char t[MAXS+1], s[MAXS+1]; 
	vector<int> help; 
	set<int> diff; 

	help.reserve(MAXS); 

	scanf("%s\n%s",t,s); 

	int big, small; 
	big = strlen(t); 
	small = strlen(s); 

	for (int i=0; i<big-small+1 ; i++) { //in case theyre equal length
						// worst case is 2*(n-1)??
		if( comp(t, s, i, small) ) 
			help.push_back(i); 
	}
	
	if ( help.size() > 1) { 
		int a, b, c, d; 
		a = help[0]; 						// |--/
		b = big - (help[ help.size()-1 ] + small); 		// /--|
		c = help[ help.size()-1 ] ; 				// |-- .. -- /	
		d = big - (help[0] + small); 				// /-- .. --|
	
		printf("%d\n", MAX(a, MAX(b, MAX(c, d))) ) ; 
	}
	else  
		printf("%d\n", MAX(help[0], big - (help[0] + small) ) ); 
	
}

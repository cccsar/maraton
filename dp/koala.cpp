#include<stdio.h> 
#include<iostream> 
#include<vector> 
#include<string.h> 

#define MAXN 100000

using namespace std; 

vector<pair<short, pair<short, bool>>> kl; 

int koala(int size, int d, int p) { // backt of solution, find a way to put it memory
	int  yo, lo, bt, cc = -1; 

	for(int i=1; i<size; i++) 
		for(int j=0; j+i<size; j++){ 
			yo = d, lo = p, bt = 0; 
			if ( kl[i].second.second )  // first kl
				if ( kl[i].second.first <= yo ) 
					yo -= kl[i].second.first; 
				else continue; 
			else 
				if (kl[i].second.first <= lo ) 
					lo -= kl[i].second.first; 
				else continue;
			bt += kl[i].first; 

			if ( kl[i+j].second.second )  // second kl 
				if ( kl[i+j].second.first <= yo )  
					yo -= kl[i+j].second.first; 
				else continue; 
			else 
				if (kl[i+j].second.first <= lo )  
					lo -= kl[i+j].second.first; 
				else continue;
			bt += kl[i+j].first; 

			cc = max(cc, bt); 
		}

	return cc ; 
} 

int main() {
	int n, d, p; 
	short u, v; 
	bool chk ;
	char t; 
	scanf("%d %d %d",&n, &d, &p); 

	for(int i=0; i<n; i++) { 
		scanf("%hd %hd %c", &u, &v, &t); 
		chk = ( t=='D' ) ? true : false; 	
		kl.push_back ( { u, { v, chk} } ); 
	}

	printf("%d\n",koala(n,d,p) ); 
}

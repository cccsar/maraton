#include<iostream> 
#include<vector> 
#include<string.h> 

using namespace std ;

vector<int> resp; 

int main() { 
	int t, n, last, mx; 
	char word[200001]; 

	cin >> t; 

	while ( t-- ) { 
		
		cin >> word ;
		last =  mx = -1; 
		n = strlen(word); 
		for(int i=0; i<n; i++) { 
			if ( word[i] == 'R' ) {
				mx = max(mx, i - last); 
				last = i ; 
			}
		}
		mx = max(mx, n - last ); 

		resp.push_back( mx ); 
	}

	for(int r : resp) cout<<r<<endl ;
}

#include<stdio.h> 
#include<deque> 
#include<unordered_set> 

const int MAXS = 200; 

int ids[MAXS] ; 

using namespace std; 

int main() { 
	int i, n, k, acc; 
	deque<int> window; 
	unordered_set<int> replicate; 
		
	scanf("%d %d",&n, &k); 

	acc = 0; 

	for( i=0; i<n; i++)  {
		scanf("%d", &ids[i]); 	
		
		if ( replicate.count( ids[i] ) == 0 ) { //if current id isn't on the screen

			replicate.insert( ids[i] ); 
			window.push_front( ids[i] ); 	//push it 

			if ( acc == k ) {  		//if full window, pop last 
				replicate.erase( window[ window.size() - 1] ) ; 
				window.pop_back(); 
			}
			else  
				acc += 1; 		//if not k keep increasing
	
		}

	}

	int q = window.size(); 
	printf("%d\n",q ); 

	for ( int k : window ) 
		printf("%d ",k ); 
	printf("\n"); 
	
	return 0; 
}

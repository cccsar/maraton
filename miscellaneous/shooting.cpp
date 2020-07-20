#include<stdio.h> 
#include<algorithm> 
#include<queue> 
#include<utility>

using namespace std; 

typedef pair<int, int> ii; 

const int MAXX = 1000; 

int ans[MAXX + 1]; 

int main() { 
	int N; 
	priority_queue< ii > my_q ;

	scanf("%d",&N); 
	
	int num; 
	for(int i=0; i<N; i++) {
		scanf("%d",&num); 
		my_q.push( {num, i} ); 
	}

	int acc = 0, it = 0; 
	while ( ! my_q.empty() ) { 
		acc += it*my_q.top().first + 1; 
		ans[ it ] = my_q.top().second + 1;  

		my_q.pop(); 
		it += 1; 
	}


	printf("%d\n",acc); 

	for (int j=0; j<N; j++) printf("%d ", ans[j]); 
	printf("\n");
}

#include <stdio.h>
#include <algorithm> 
#include <vector>
#include <cmath>

using namespace std; 

vector<int> cc; 

int main() { 
	int N, v; 

	scanf("%d %d",&N, &v); 
	cc.resize(N); 
	for(int i=0; i<N; i++) scanf("%d", &cc[i]);  

	printf("%d\n", binary_search(cc.begin(), cc.end(), v)); 	
}

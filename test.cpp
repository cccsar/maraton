#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 

#define FOR(i,u,l) for(i=l; i<u; i++) 
#define ROF(i,l,u) for(i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)

#define RS 256
	
using namespace std; 

int main() 
{
	char *a = (char*) malloc( 2 * sizeof(char)) ; 
	int i_; 

	printf("initiall addr of ptr: %p\n",a );
	FOR(i_, 0, 255) {
	       	*(a+i_) = i_%256; 
		printf("addr of ptr after some changes: %p\n",a+i_); 
	}

	free(a); 

	return 0; 
}

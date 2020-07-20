#include<iostream> 
#include<stdio.h>
#include<algorithm> 

using namespace std; 

#define FOR(i,l,u) for(i=l; i<u; i++) 
#define ROF(i,u,l) for(i=u; i>l; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
	
int stands[1000000];
int diff[1000000];

int main() 
{
	int n_,k_,i_, acum; 

	rii(n_,k_) ;	

	FOR(i_, 0, n_) 
		ri(stands[i_]); 

	sort(stands,stands+n_);

	diff[0] = 0 ;
	FOR(i_, 1, n_) 
		diff[i_] = stands[i_]-stands[i_-1] - k_;

	FOR(i_, 0, n_) 
		cout<<stands[i_]<<" ";
	cout<<endl;

	FOR(i_, 0, n_) 
		cout<<diff[i_]<<" ";
	cout<<endl;
		
	return 0; 
}

#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>

using namespace std; 

#define FOR(i,l,u) for(i=l; i<u; i++) 
#define ROF(i,u,l) for(i=u; i>l; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
	
int alpha[20]; 
char word[3*100000];

int main() 
{
	int n_,i_, temp, max_mugs, n_odd, n_even;
	n_odd = n_even = 0;

	ri(n_);
	scanf("%s",word); 
	
	max_mugs = 1; 

	FOR(i_, 0, n_) {
		temp = word[i_]%97;	
		alpha[ temp ] ++;

		if ( alpha[temp]%2==0) {
			n_even++; 
			n_odd--; 
		}
		else { 
			if (alpha[temp] != 1) 
				n_even--;
			n_odd++;
		}

		if( (n_odd==0 || n_odd==1) && n_even >= 0)  
			max_mugs = i_+1;
	}

	i_ = 0;
	while( alpha[ word[i_]%97 ]==1 && n_odd!=1) {
		n_odd--; 
		word[i_] = 0;
		i_++; 
	}
			


	FOR(i_,0,20) 
		cout<<alpha[i_]<<" ";
	cout<<endl;

	cout<<max_mugs<<endl;

	return 0; 
}

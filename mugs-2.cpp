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

int maxCount(int al[], char wd[], int n_, int low) {

	int i_, temp, n_even, n_odd, max_mugs;

	n_even = n_odd = 0;
	max_mugs = 1;

	FOR(i_, low, n_) {
		temp = wd[i_]%97;	
		al[ temp ] ++;

		if ( al[temp]%2==0) {
			n_even++; 
			n_odd--; 
		}
		else { 
			if (al[temp] != 1) 
				n_even--;
			n_odd++;
		}

		if( (n_odd==0 || n_odd==1) && n_even >= 0)  
			max_mugs = i_+1 - low;
	}

	return max_mugs;
}


int main() 
{
	int n_,i_, j_, temp, max_mugs, n_odd, n_even;
	bool late;

	n_odd = n_even = 0;
	late = false; 

	ri(n_);
	scanf("%s",word); 
	
	max_mugs = maxCount(alpha, word, n_, 0);

	i_ = 0;
	while( alpha[ word[i_]%97 ] == 1 ) {
		late = true; 
		i_++; 
	}

	FOR(j_,0,20) 
		alpha[j_] = 0;

	if(late) 
		max_mugs = maxCount(alpha, word, n_, i_-1);


	cout<<max_mugs<<endl;

	return 0; 
}

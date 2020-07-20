#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 

#define FOR(i,l,u) for(i=l; i<u; i++) 
#define ROF(i,u,l) for(i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rl(c) scanf("%lld",&c);

#define PRIME 1000000007
	
using namespace std; 

unsigned long long f_des[500]; 
unsigned long long f_norm[500];

void fact(int n_) {

	int i_; 
	f_norm[0] = 1; 

	FOR(i_,1,n_+1)  {
		f_norm[i_] = f_norm[i_-1]*i_ % PRIME;
	}

	//return f_norm[n_];
}

void fact_desc(int n_, int m_) { 
		
	int i_; 
	f_des[0] = 1 ;
	f_des[1] = n_; 

	FOR(i_,2,m_) { 
		f_des[i_] = f_des[i_-1]*( n_-(i_-1) ) % PRIME ; 
	}

	//return f_des[m_]; 

}

int main() 
{
	int a_,b_,k_,c_, sum, i_;

	rii(a_,b_);
	rii(k_,c_); 

	sum = 0; 
	
	fact(k_/2+1); 
	fact_desc(k_, k_/2 +1);

	/* revisar esto */
	if ( c_==a_ || c_==b_ ) { 
		FOR(i_, 0, k_/2+1) {
			if(i_ >= k_/2 + 1)  
			       	sum +=  f_des[k_-i_]/f_norm[k_-i_]; 
			else	
				sum +=  f_des[i_]/f_norm[i_];
		}
		sum *= k_; 
	} 
		
	cout<<sum<<endl;
		
	return 0; 
}

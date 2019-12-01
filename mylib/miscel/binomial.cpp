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

/* Maximum factorial smaller than maximum unsigned integer
 * and unsigned long long (imp_), yet to determine */ 
unsigned long long f_des[500]; 
unsigned long long f_norm[500];

void fact(int n_) {

	int i_; 
	f_norm[0] = 1; 

	FOR(i_,1,n_+1)  {
		f_norm[i_] = f_norm[i_-1]*i_;
		cout<<f_norm[i_]<<endl;
	}

	//return f_norm[n_];
}

/* Descending factorial */ 
void fact_desc(int n_, int m_) { 
		
	int i_; 
	f_des[0] = 1 ;
	f_des[1] = n_; 

	FOR(i_,2,m_) 
		f_des[i_] = f_des[i_-1]*( n_-(i_-1) ) ; 

	//return f_des[m_]; 

}

int main() 
{
	int k_, sum, i_ , temp, o_temp;
	ri(k_); 

	sum = 0; 
	
	/* Here calculate up to k_/2 + 1, factorials (both descendant 
	 * and normal) and saved them in global arrays. This to avoid
	 * further calculation given the formula
	 * 	bin(a,b) = fact_desc(a,b) / fact_desc(b)
	 * 	where cancelation of factors starts at k_/2 + 1
	 *
	 * It only makes sense to calculate up to a number not greater
	 * than maximum representable. If it is not the case, include 
	 * modulo some prime. 
	 */ 
	fact(k_/2+1); 
	fact_desc(k_, k_/2 +1);

	/* This calculates Sigma( binomial(k_,i_) ) where 0<= i_<=k_ */
	cout<<"Pascal triangle"<<endl;
	FOR(i_, 0, k_+1) {
		if(i_ >= k_/2 + 1)  {
		       	temp =  f_des[k_-i_]/f_norm[k_-i_]; 
		}
		else {	
			temp =  f_des[i_]/f_norm[i_];
		}
		/* Priting pascal triangle associated*/
		cout<<temp<<" ";	

		sum+=temp;
	}
	
	cout<<endl<<"Total: "<<sum<<endl;	
	return 0; 
}

#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<set> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 
#include<math.h>

using namespace std; 

#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",&s)

typedef vector< int > vi; 
typedef vector< pair<int, int> >  vii; 
typedef vector< int, pair<int, int> >viii; 
typedef pair <int, int> pi; 
typedef pair <int, pair<int, int> > pii; 
typedef vector< vi > adl; 
typedef vector< vii > wadl; 

const int MAXINT = 2147483647;

const int MAXT = 100;
const int MAXS = 1000000000; 

bool sieve[MAXS]; 
pii *resp = new pii[MAXT]; 

void primes(int e, vi &divisible) { 
	int c, acc, bound, i_; 

	bound = floor( sqrt(e) ) ; 

	c = 2; 

	while ( c<=bound ) {
		if ( !sieve[c] ) {	//check if hasn't been marked
			if ( e % c == 0) {  		//if divisible by e save it
				divisible.push_back ( c );
				if( divisible.size() == 3) 
					break; 
			}

			acc = 2 * c; 
			while ( acc <= e ) { 	//exclude all multiples of free elemnt found
				
				sieve[ acc ] = true ;

				acc += c; 
			}
		}
		c += 1; 
	}

	for(i_=bound + 1; i_<e && divisible.size() != 3; i_++) {
		if ( !sieve[i_] && e%i_==0 ) 
			divisible.push_back ( i_ ); 	//include remaining divisors
	}	

}


void foo(int e, vi &dvs, int index ) { 
	int a, b, c, pw, pwa, pwb; 
	
	if ( dvs.size() == 0 ) { 
		resp[index].first = -1 ;
	}
	else if ( dvs.size() ==1 ) { 
		pw = pow( dvs[0], 6); 
		
		if ( e >= pw ) { 
			a = dvs[0]; 
			b = pow( a, 2) ; 
			c = e/(a * b); 

			resp[index] = {a, {b,c} } ; 
		}	
		else 
			resp[index].first = -1; 

	}
	else if ( dvs.size() == 2) { 
		pwa = pow( dvs[0], 3 ); 
		pwb = pow( dvs[1], 3 ); 

		if ( e >= pwa ) { 
			a = dvs[0]; 
			b = pow(a, 2); 
		       	c = e/(a * b) ; 

			resp[index] = { a, {b, c} } ;	
		}
		else if ( e >= pwb ) { 
			a = dvs[1]; 
			b = pow(a, 2); 
		       	c = e/(a * b) ; 

			resp[index] = { a, {b, c} } ;	
		}
		else { 
			resp[index].first = -1; 
		}
	}
	else { 
		a = dvs[0]; 
		b = dvs[1] ; 
		c = e/(a*b) ;
		resp[index] = {a, {b, c} } ; 
	}
}


int main() 
{
	int n, t, i_, j_; 
	vi divisible;

	ri(t); 

	for(i_=0; i_<t ;i_++) { 
		ri(n); 

		primes(n, divisible); //recover at most 3 primes factor of n to div
		foo(n , divisible, i_ ); 


		//clear
		for(j_=0; j_<n ;j_++)  //overhead of this is gonna killme
			sieve[i_] = false ;
		divisible.clear(); 
	}		

	for(i_=0; i_<t ;i_++) { 
		if ( resp[i_].first != -1 ) { 
			cout<<"YES"<<endl; 
			cout<<resp[i_].first<<" "<<resp[i_].second.first<<" "<<resp[i_].second.second<<endl; 
		}
		else
			cout<<"NO"<<endl; 
	}	
		

	return 0 ;
}

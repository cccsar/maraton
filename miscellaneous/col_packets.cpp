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
#include<string.h> 

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
const int MAXS = 1000; 
const int MAXWSIZE = 10000 ;
const char U = 'U'; 
const char R = 'R'; 

pi test[MAXS + 1];
bool resp[MAXT] ; 
char steps[MAXT][MAXWSIZE] ;



void apd(char * dest, const char let, int size )  { 
	int i_ ;
	char help[size] ;

	for(i_=0; i_<size ; i_++) 
		help[i_] = let; 	
	
	if ( size != 0 ) 
		strncat(dest, help, size); 
}


int main() 
{
	int t, n, a, b , c, i_; 
	bool check; 

	ri(t); 

	test[0].first = 0 ;
	test[0].second = 0; 

	c = t; 
	while ( c > 0) { 
		ri(n); 
		check = true; 

		for(i_=0; i_<n ; i_++) {
			rii(a,b); 
			test[i_+ 1].first = a ;
			test[i_+1].second = b ; 
		}	

		sort(test, test + n + 1); 	//sort coordinates by x	
			
		for(i_=1; i_<n+1 ; i_++) { //check if sequence of sorted pairs is non decreasing
			if ( test[i_-1].first > test[i_].first ) { 
					check = false; 
					break; 
			}
			else { 
				if ( test[i_-1].second > test[i_].second ) { 
					check = false ;
					break; 
				}
				
				apd( steps[t-c], R, test[i_].first - test[i_-1].first ); //accumulate R
				apd( steps[t-c], U, test[i_].second - test[i_-1].second ); 
			}

		}	

		if ( check ) { 
			resp[t-c] = true; 
		}
		else //if non decreasing or irregular isn't posible
			resp[t-c] = false; 

		c -= 1; 
	}


	for(i_=0; i_<t ; i_++) {
		if ( resp[i_] ) { 
			cout<<"YES"<<endl; 
			cout<<steps[i_]<<endl; 
		}
		else  
			cout<<"NO"<<endl; 
	}	

	return 0; 
}

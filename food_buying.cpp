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

const int MAXT = 10000;

int resp[MAXT] ;

int foo(int e ) { 
	int temp, quot, rem , ans; 

	temp = quot =  e ;
	while ( true)  { 

		rem = quot % 10  ;
		ans = quot / 10;

		if ( ans + rem >= 10 )  {
			temp += quot ;  
			quot = ans ; 
		}
		else { 
			temp += rem; 
			break; 
		}
	}

	return temp ;

}


int main() 
{
	int t, c, help, i_ ;

	ri(t); 

	c = t+1; 	
	while (c --) { 

		ri(help ); 

		resp[t-c] = (help<10)? help: foo(help); 
	}

	for(i_=0; i_<t ; i_++)
		cout<<resp[i_]<<endl; 


	return 0; 
}

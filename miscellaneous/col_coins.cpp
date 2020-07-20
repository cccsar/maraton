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
const int SIS = 3; 

bool resp[MAXT]; 
int ord[SIS]; 

int myMax(int *arr, const int size) { 
	int i_, ret; 
		
	ret = -1 ;
	for(i_=0; i_<size ; i_++) {
		if ( arr[i_] > ret ) 
			ret = arr[i_] ; 
	}	

	return ret; 
		
}
int main() 
{
	int t, n, i_, k , sum, grand; 

	ri(t); 

	k = t ; 
	while ( k != 0) { 
		if (k == 0 )
			break; 
		riii(ord[0], ord[1], ord[2]); 
		ri(n); 


		sum = ord[0] + ord[1] + ord[2] + n; 

		grand = myMax(ord, 3) ; 

		if ( sum >= 3 )  { 
			if( ( 3*grand - (ord[0] + ord[1] + ord[2] ) ) < n ) 
				resp[t-k] = ( sum%3 == 0)? true: false; 
			else
				resp[t-k] = false; 
		}
		else 
			resp[t-k] = false; 
		 k-= 1;
	}

	for(i_=0; i_<t ; i_++) 
		( resp[i_] )? cout<<"YES"<<endl : cout<<"NO"<<endl;

	return 0; 
}

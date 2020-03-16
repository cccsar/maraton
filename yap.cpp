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

const int MAXS = 5000; 
const int MAXT = 100;

bool resp[MAXT] ; 
int times[MAXS+1], word[MAXS+1] ;

int main() 
{
	int t, n, c, i_, j_; 
	bool stat; 
	
	for(i_=0; i_<MAXS ; i_++)  
		times[i_] = 0; 

	ri(t) ;
	c = t+1;

	while( c-- ) { 
		stat = false; 

		ri(n); 
		for(i_=0; i_<n ; i_++) {
			ri(word[i_]); 		
			times[ word[i_] ] +=1 ;
		}	

		for(i_=0; i_<n ; i_++) {
			if ( times[ word[i_] ] <= 1) 
				continue; 
			
			if ( times[ word[i_] ] == 2 && n > 2) {
				if ( word[i_] != word[i_+1] ) {
					stat = true; 
					break; 
				}
				i_+=1; 
			}	
			else  if ( times[ word[i_] ] > 2 ){
				stat = true; 
				break; 
			}
		}	


		resp[t-c] = stat;  

		for(i_=0; i_<n ; i_++) 
			times[ word[i_] ] = 0 ;
	}

	for(i_=0; i_<t ; i_++) 
		(resp[i_])? cout<<"YES"<<endl : cout<<"NO"<<endl;

	return 0; 
}

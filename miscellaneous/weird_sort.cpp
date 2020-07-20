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

const int MAXS = 100;

int arr[MAXS] ,swaps[MAXS]; 
bool resp[MAXS], vtd[MAXS]; 

int main() 
{
	int t, n, m, c, i_, tmp, cnt, help, ind, bound; 
	bool guard; 

	ri(t); 

	c = t + 1;
	for(i_=0; i_<MAXS ; i_++) {
		swaps[i_] = -1 ;
		vtd[i_] = false; 
	}

	while ( c-- ) { 

		tmp = cnt = -1; 
		guard = true; 

		rii(n, m);// read array for sorting
	       		//and check the prefix already sorted
			//in non decreasing	

		for(i_=0; i_<n ; i_++) {
			ri(arr[i_]); 

			if ( guard ) {
				if ( arr[i_] >= tmp ) { 
					if (tmp != -1)
						cnt += 1;
					tmp = arr[i_] ; 
				}
				else 
					guard = false ;
			}

			if ( help > arr[i_] )  
				ind = i_ ;

			help = arr[i_] ; 
		}	

		for(i_=0; i_<m ; i_++) {
			ri(swaps[i_]); 
			vtd[ swaps[i_] ] = vtd[ swaps[i_] - 1] = true; 
		}	

		for(i_=0; i_<n ; i_++) {
			cout<<vtd[i_]<<" "; 
		}	
		cout<<endl;

		bound = (cnt <= ind )? ind : n ;
		
		cout<<"cnt: "<<cnt+1<<" bound:"<<bound<<endl;
		
		for(i_=cnt+1; i_<bound ; i_++) {
			if ( !vtd[i_] ) {
				cout<<"hola"<<endl;
				resp[t-c] = true; 
				break; 
			}
		}	

		for(i_=0; i_<n ; i_++) {
			swaps[i_] = -1 ;
			vtd[i_] = false; 
		}

	}

	for(i_=0; i_<t ; i_++) {
		(!resp[i_])? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}	


	return 0; 
}

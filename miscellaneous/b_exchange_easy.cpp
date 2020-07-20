
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

const int MAXX = 200; 

int mark[MAXX + 1]; 
int arr[MAXX]; 
vi *resp = new vi[MAXX]; 

int main() 
{
	int q, n, i_, j_ , marker, fst, dum, cnt;  

	ri (q); 

	for(i_=0; i_<MAXX ;i_++)  
		mark[i_] = -1; 

	for(i_=0; i_<q ;i_++) { 

		marker = 1 ; 
		ri(n); 

		for(j_=0; j_<n ;j_++)  
			scanf("%d",&arr[j_]); 

		resp[i_].resize(n); 

		for(j_=0; j_<n ;j_++) { 


			if ( resp[i_][j_] == 0 ) { 
				cnt = 1; 
				fst = arr[j_] ; 
				dum = arr[ fst - 1 ] ; 
	
				resp[i_][ j_ ]  = marker;  //mark first element with ith marker
	
				while ( dum != fst ) { 
	
					resp[i_][ dum - 1] = marker;  //mark every element of cicle with marker
					dum = arr[ dum - 1]  ; 
					cnt += 1;
				}
	
				mark[ marker ] = cnt; //associate length of the cicle with marker
	

				marker += 1;  //increase marker
			}
		}	

		for(j_=0; j_<n ;j_++) { 
			resp[i_][j_] =  mark[ resp[i_][j_] ] ; //asign as response associated markers
		}	

	}	

	for(i_=0; i_<q ;i_++) { 
		for(int k : resp[i_] ) 
			cout<<k<<" "; 
		cout<<endl; 
	}	

	return 0; 
}

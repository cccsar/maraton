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


const int TCASES = 1000;
const int MATMAX = 100;

bool resp[TCASES];
int letters[MATMAX][MATMAX];
vii begins; 	

void successors() { 

}

int main() 
{
	int t, r, c, i_, j_, k_, letra; 
	pi dummie; 

	ri(t); 

	for (i_=0 ; i_<t ; i_++) { 

		rii(r, c);		
		for (j_=0 ; j_<r ; j_++) { 
			for (k_=0 ; k_<c ; k_++) { 
				scanf("%c", letra); //cambiar todo esto por char
				letters[j_][k_] = letra;
				if (  == "A" ) {
					dummie.first = j_; 
					dummie.second = k_; 
					begins.push_back(dummie); 
				}
			}	
		}	

		
		

	}

	return 0; 
}

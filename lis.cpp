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
	

const int MAXS = 100000000;

int zet[MAXS]; 
vector<int> *liss = new vector<int>[MAXS]; 

void lis(){ 
	//get index and latest found, if zet[index] is greater than latest found
	//then becomes latest found and is accumulated into a vector
}


int main() 
{
	int n, e; 

	scanf("%d", &n); 

	for(int k=0; k<n; k++) {
		scanf("%d", &e); 
		zet[k] = e; 
	}

	return 0; 
}

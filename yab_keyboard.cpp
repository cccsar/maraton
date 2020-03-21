
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
#include<unordered_map>

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

const int MAXL = 200000; 
char word[MAXL+1];

int main() 
{
	int n, k , i_, last, curr;
	long long tot; 
	char e; 
	unordered_map<char, bool> lett; //hash table for valid letters of the kb

	tot = 0; 
	last = curr = -1; 

	rii(n, k); 

	scanf("%s",word); 

	for(i_=0; i_<k ;i_++) { 
		scanf(" %c",&e); 
		lett[e] = true; 
	}

	for(i_=0; i_<n ;i_++) { 
		if( !lett.count(word[i_]) ) { //if it isn't a valid letter save position 
					//and check if change
			if ( curr > last ) 
				tot += (curr-last)*(curr-last+1)/2; 
			last = i_; 
		}
		else  
			curr = i_;	

	}	

	if( lett [ word[n-1] ] ) 
	       tot += (n-1-last)*(n-last)/2;	


	cout<<tot<<endl; 

	return 0; 
}

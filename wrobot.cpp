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


const int MAXS = 200000;
const int MAXT = 1000; 
const int MAXMIN = 4; 

int resp[MAXT] ;
char steps[MAXS+1]; 
pi ext[MAXT]; 

int main() 
{
//	U 85 L 76 R 82 d 68
	int t, c, i_, size, help, temp; 
	bool found; 

	ri(t); 

	c = t + 1;

	while( c--){ 
		found = false; 

		ri(size); 
		scanf("%s",steps); 

		for(i_=1; i_<size ; i_++) {
			help = abs(steps[i_] - steps[i_ -1]); 

			if ( help == 17 || help == 6 )  {
				ext[t-c].first = i_; 
				ext[t-c].second = i_+1; 

				found = true; 
				break; 
			}

			if ( i_ >= 3) {
				temp = steps[i_-3] + steps[i_-2] + steps[i_-1] + steps[i_]; 

				if ( temp == 311)   {
					ext[t-c].first = i_-2; 
					ext[t-c].second = i_ + 1; 
					found = true; 
				}
			}

		}	

		resp[t-c] = found; 
	}


	for(i_=0; i_<t ; i_++) 
		(resp[i_])? cout<<ext[i_].first<<" "<<ext[i_].second<<endl: cout<<"-1"<<endl;; 

	return 0; 
}

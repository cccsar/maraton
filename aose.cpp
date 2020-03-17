#include<iostream> 
#include<stdio.h>
#include<vector>
#include<queue>

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

int resp[MAXT];

int main() 
{
	int t, a, b, c, i_; 

	ri(t);
	c = t+1; 

	while (c--) { 
		rii(a,b); 

		if (a > b) { 
			if(a%2==0 && b%2==0)  
				resp[t-c] = 1; 	
			else if ( a%2==0 && b%2==1) 
				resp[t-c] = 2; 
			else if ( a%2==1 && b%2==0)
				resp[t-c] = 2; 
			else
				resp[t-c] = 1; 
		} else if (a<b){ 

			if(a%2==0 && b%2==0)  
				resp[t-c] = 2; 	
			else if ( a%2==0 && b%2==1) 
				resp[t-c] = 1; 
			else if ( a%2==1 && b%2==0)
				resp[t-c] = 1; 
			else 
				resp[t-c] = 2;
		} else 
			resp[t-c] = 0; 

	}

	for(i_=0; i_<t ; i_++) 
		cout<<resp[i_]<<endl; 

	return 0; 
}

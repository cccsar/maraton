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


#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",&s)
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 


	
using namespace std; 

int mex(vector<int> multiset, int *imp){ 
	int resp, ref;
	set<int> help; 
	set<int>::iterator it; 

	resp = 0 ;

	for(int i_: multiset) 
		help.insert(i_); 

	if ( help.size()  == 0)
		return 0 ;
	else {
		ref = 0; 
		//search for minimum excluded value
		for (it = help.begin(); it!=help.end(); it++)  {

			if (*it != ref) 
				break ;
			ref += 1;
		}

		//update number of colorations on maximum
		if ( it == help.end()) {
			resp = ref 
		}
		else
			resp = *it -1; 

		if( resp > *imp)
			*imp = resp;
		return resp ;	
		
	}
}

int main() 
{
	int i_, imp, n, e, aux; 
	vector<int> aiuda; 

	ri(n); 
	aux = 0 ;
	for(i_=0; i_<n ; i_++) {
		ri(e);
		aiuda.push_back(e);
	}	

	cout<<mex(aiuda, &aux)<<endl; 
       	cout<<aux<<endl; 

	return 0; 
}


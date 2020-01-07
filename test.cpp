#include<iostream> 
#include<stdio.h>
#include<algorithm> 
#include<set> 
#include<string> 
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<utility>
#include<climits> 
#include<unordered_map>


#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define rw(s) scanf("%s",s)
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 

#define UB 5 
#define MAXSS 10
	
using namespace std; 

int main() 
{
	unordered_map <string, int> mmap; 
	string hola, como; 
	int i_, val; 

	for(i_=0; i_<UB ; i_++) {
		cin>>hola>>val; 
		mmap[hola] = val ;
	}
	cout<<"Queries\n";
	
	for(i_=0; i_<UB ; i_++) {
		cin>>como; 
		cout<<mmap[ como ] <<endl; 
	}	
	for(auto it: mmap) 
		cout<<it.first<<" "<<it.second<<endl;
	
	
	return 0; 
}

#include<iostream> 
#include<stdio.h>
#include<algorithm> 
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
#define rl(a) scanf("%lld",&a)
#define vi vector< pair<int, int> >  
#define vii vector< int, pair<int, int> >

	
using namespace std; 

//Trace bug on 64 input

long long hanoi(long long a) { 
	if (a == 1) 
		return 1; 
	return 2*hanoi(a-1) + 1;
}

int main() 
{
	long long a; 
	rl(a);

	cout<<hanoi(a)<<endl;

	return 0; 
}

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
//#include <math.h> 


#define FOR(u,l) for(int i=l; i<u; i++) 
#define ROF(l,u) for(int i=u; i>l-1; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
#define riii(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 

int cost[200000];

int resp[10000]; 

using namespace std; 

int figureOut(int bin, int size, int total){
	int it, running; 

	it = bin; 
	running = total; 

	while ( running >= cost[it] && it < size) { 
		running -= cost[it] ; 
	
		if ( it == total - 2 ) 
			it += 1; 
		else 
			it +=2; 
	}

	return (it > 0)? it - 1: 0 ; 

}	

int main() 
{
	int t_, n_, p_, k_, i_, j_, temp, first, second; 

	ri(t_); 

	for(i_=0; i_<t_ ; i_++) {
		
		riii(n_, p_, k_); 
		for(j_=0; j_<n_ ; j_++) {
			ri(temp); 	
			cost[j_] = temp ;
		}			

		sort(cost, cost+n_); 

		first = figureOut(0, n_, p_);
		second = figureOut(1, n_, p_); 

		resp[i_] = max( first, second); 

	}

	for(i_=0; i_<t_ ; i_++) 
		cout<<resp[i_]<<endl; 	

	return 0; 
}

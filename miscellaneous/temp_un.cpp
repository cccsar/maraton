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
#define vi vector< int > 
#define vii vector< pair<int, int> >  
#define viii vector< int, pair<int, int> >
#define pi pair <int, int> 
#define pii pair <int, pair<int, int> > 
#define adl vector< vi > 
#define wadl vector< vii > 

int resp [1000];
	
using namespace std; 

int main() 
{
	int t_, a_, b_, c_, r_, i_, ub, lb, fs, ss, first, second, whole; 

	ri(t_); 

	for(i_=0; i_<t_ ; i_++) {
		rii(a_,b_); 
		rii(c_,r_); 


		if ( abs(a_-b_) != 0) { 
			ub = max(a_,b_); 
			lb = min(a_,b_); 
			fs = c_ - r_; 
			ss = c_ + r_; 
			whole = abs(ub - lb); 

			if ( lb <= c_ ) { 
				
				if ( ub >= c_ ) { 
					first = (ss < ub)? r_: ub - c_ ; 
					second = (fs > lb)? r_: c_ - lb ;  

					resp[i_] = whole - (first + second);  
				}
				else  	
					if ( fs < ub)  
						resp[i_] = (fs > lb)? whole - (ub - fs) : whole - (ub - lb); 
					else 
						resp[i_] = whole ;

			}
			else  
				if (ss > lb)  
					resp[i_] = (ss < ub)? whole - (ss - lb): whole- (ub - lb); 
				else 
					resp[i_] = whole; 


		}
		else  
			resp[i_] = 0;  
		
	}

	for(i_=0; i_<t_ ; i_++) 
		cout<<resp[i_]<<endl; 

	return 0; 
}

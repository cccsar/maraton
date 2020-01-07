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
	
using namespace std; 

vector< pair<int, bool> > desc; 
int resp[200000]; 

bool isValid(int easy_t, int hard_t, int it, int ind, int size, int elapsed) { 
	int acum ; 

	acum = elapsed; 
	while( ind == desc[it].first) {
		acum += (desc[it].second)? hard_t: easy_t; 
		it ++ ;
	}


	if (it < size-1)  {
		/*cout<<" acum: "<<acum<<" desc[it].first: "<<desc[it].first<<endl; */
		return (acum < desc[it].first)? true: false; 
	}
	else
		return false; 

}

int figureOut(int t_time, int n_questions, int easy_t, int hard_t) { 
	int valid, i_, et; 
	valid = -1; 
	et = 0; 

	for(i_=0; i_<n_questions && et + desc[i_].first <= t_time ; i_++) {

		/*cout<<isValid(easy_t, hard_t, i_, desc[i_].first, n_questions, et)<<endl; */
		/*if ( isValid(easy_t, hard_t, i_, desc[i_].first, n_questions, et) ) */
		if (et <= desc[i_].first)
			valid = i_ + 1;
		
		et += (desc[i_].second)? hard_t: easy_t; 

	}		


	if( i_ == n_questions && valid != -1) {
		return n_questions; 
	}
	else {
		return (valid!= -1)? valid : 0; 
	}
}

int main() 
{
	int i_, j_, m_,n_, a_, b_, t_, temp, catched;
	pair<int, bool> dummie; 
	vector< pair<int, bool> > :: iterator lb ; 
	vector< pair<int, bool> > :: iterator ub ; 

	ri(m_); 
	for(i_=0; i_<m_ ; i_++) {
		rii(n_, a_); 
		rii(b_, t_); 	
		
		for(j_=0; j_<n_ ; j_++) {
			ri(temp); 
			dummie.second = (temp)? true: false ; 
			desc.push_back(dummie); 
		}	
		for(j_=0; j_<n_ ; j_++) {
			ri(temp);
			desc[j_].first = temp;  
		}		


		lb = desc.begin();
		ub = desc.end();

		sort(lb, ub); 

		resp[i_] = figureOut(t_, n_, a_,b_);   

		desc.clear(); 
	}

	for(i_=0; i_<m_ ; i_++) {
		cout<<resp[i_]<<endl; 	
	}

	return 0; 
}

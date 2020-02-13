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

int books[200], resp[200][200], size[200]; 


int foo(int e){
	int count, dummie ; 
	count = 1; 
	dummie = e; 

	while ( books[dummie] != e) {
		count++ ;
		dummie = books[dummie];
	}
	
	return count; 

}


int main() 
{
	int q, n, i_, u, j_; 

	ri(q); 

	for (i_=0 ; i_<200 ; i_++) { 
		books[i_] = -1; 
	}

	for (i_=0 ; i_<q ; i_++) { 

		ri(n); 
		size[i_] = n; 

		for (j_=0 ; j_<n ; j_++) { 
			ri(u); 
			books[j_] = u; 
		}

		for (j_=0 ; j_<n ; j_++)  
			resp[i_][j_] = foo( books[j_] ) ; 


		for (j_=0 ; j_<n ; j_++) { 
			books[j_] = -1; 
		}
	}

	for (i_=0 ; i_<q ; i_++) { 

		for (j_=0 ; j_<size[i_] ; j_++)  
			cout<<resp[i_][j_]<<" "; 
		cout<<endl; 
	}

	return 0; 
}

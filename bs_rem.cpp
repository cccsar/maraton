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
#include<math.h> 

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
	
bool bs(int arr[], int e, const int p, const int q) { 

	int k = p + (q-p)/2 ; 
	//cout<<"p:"<<p<<" q:"<<q<<endl; 
	//cout<<"arr["<<p<<"]: "<<arr[p]<<" arr["<<q<<"]:"<<arr[q]<<endl; 

	//cout<<"sol: "<<arr[k]<<endl; 
	if ( arr[k] > e ) {
		if ( p == q - 1) 
		return bs(arr, e, p, k); 
	}	
	else if ( arr[k] < e ){ 
		if ( p == q - 1 ) 
			return (arr[q] != e )? false: true;
		return bs(arr, e, k, q ); 
	}

	return true; 
}

int main() 
{
	int cost[100], i_; 
	int k ;

	for(i_=0; i_<100 ; i_++) 
		cost[i_] = i_ ;   
	
	
	for(i_=0; i_<100 ; i_++) {
		k = bs(cost, i_, 0, 99); 
		( k == true)? cout<<"encontrado"<<endl: cout<<"no encontrado"<<endl; 
	}	

	k = bs(cost, -1, 0, 99); 
	( k == true)? cout<<"encontrado"<<endl: cout<<"no encontrado"<<endl; 
	k = bs(cost, 101, 0, 99); 
	( k == true)? cout<<"encontrado"<<endl: cout<<"no encontrado"<<endl; 


	cout<<k<<endl;
	return 0; 
}

#include<stdio.h>
#include<iostream> 
#include<utility> 
#include<algorithm> 
#include<vector> 


#define MAXINT 0x7fffffff
#define MAXN 500
#define MAXT 1000
#define MAXW 10000


using namespace std; 

typedef pair<int, int> pi ; 
typedef vector<pi> vii; 

vii wc ; 
int dp[2][MAXW][MAXN]; // memory
int resp[MAXT] ; 

pi  foo (int p, int ind ) { //not a solution of the problem
	int quot = p / wc[ind].first; 
	int rem = p % wc[ind].first; // is it always p >= wc[ind].first == true ?? 
	int tot = quot * wc[ind].second; 
	int ix = 0;
	pi rep = { MAXINT, MAXINT } ; 

	while ( wc[ix].first <= rem ) {
			
		rep = min( rep , foo ( rem, ix ) ); 
		ix +=1; 	
	}

	if ( rep.first == MAXINT ) 
		return { tot, quot*wc[ind].first } ; 
	return { tot + rep.first, quot*wc[ind].first + rep.second } ;  
}

pi wubba(int p, int ind) { // it does produces a time enhacement of solution according to judge
	int quot = p / wc[ind].first ; 
	int rem = p % wc[ind].first ; 
	int tot = quot * wc[ind].second;  
	pi rep = {MAXINT, MAXINT } , help ; 
	int ix = 0; 

	while ( wc[ix].first <= rem ) { 
		if ( dp[0][rem][ix] == -1 ) {  // check in your memory or put in your memory
			help = wubba(rem,ix); 
			dp[0][rem][ix] = help.first; 
			dp[1][rem][ix] = help.second;  
		}
		rep = min ( rep , { dp[0][rem][ix], dp[1][rem][ix] } ) ; // ###
		ix +=1; 
	}

	if ( rep.first == MAXINT ) 
		return { tot, quot * wc[ind].first } ; 
	return { tot + rep.first, quot * wc[ind].first + rep.second }; 
}

int main() { 
	int n,t,k, e, f, p, w, c; 

	scanf("%d",&t); 

	k = t; 

	while ( k-- ) { 
		scanf("%d %d",&e, &f); 

		p = f - e; 

		scanf("%d", &n); 

//		for(int i=0 ;i<2; i++) 
//			for(int j=0; j<p ;j++) 
//				for(int k=0; k<n; k++) 
//					dp[i][j][k] = -1; 

		for(int i=0; i<n; i++) { 
			scanf("%d %d",&c, &w); 
			wc.push_back( { w, c } ); 
		}


		// algorithm goes here

		sort(wc.begin(), wc.end()); 

		pi  menor = { MAXINT, MAXINT }; 
		pi  test; 
		for(int i=0; i<n; i++){
			test = foo (p, i); 	
//			printf("%d %d\n",test.first, test.second); 
			if ( test.second == p ) 
			       	menor = min( menor, test ); 
		}
//		printf("\n"); 

		resp[t-k-1] = (menor.first == MAXINT)? -1 : menor.first; 
//		printf("%d %d\n",menor.first, menor.second ); 
//		printf("\n\n"); 

		// 

		wc.clear(); // cleaning
	}

	for(int i=0; i<t; i++)  
		if ( resp[i] == -1 )
			printf("This is impossible.\n"); 
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",resp[i]); 
}

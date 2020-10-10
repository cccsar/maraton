#include<stdio.h> 
#include<iostream> 
#include<utility> 
#include<vector> 
#include<algorithm> 
#include<set> 

#define MAXN 100000

using namespace std ;

int tch[MAXN], st[MAXN], diffs[MAXN], zs[MAXN]; 
long long tots[MAXN]; 
set<pair<int, int>> pos, neg; 

//vector< pair<int, int> > diffs(MAXN); 

int main() { 
	int n, acc = 0, accz = 0; 

	cin >> n; 

	for(int i=0 ;i<n; i++) cin >> tch[i]; 
	for(int i=0; i<n; i++) cin >> st[i]; 

	for(int i=n-1 ;i>=0; i--) { 
		diffs[i] = tch[i] - st[i]; 
		if ( diffs[i] >= 0 ) { 
			acc +=1; 
			tots[i] = acc ;
			if ( diffs[i] == 0 ) { 
				accz +=1; 
				zs[i] = accz; 
			}
			pos.insert({ i, diffs[i] } ); 
		}
		else
			neg.insert({ i, diffs[i] } ); 

	}

	long long resp = 0; 
	for(int i=0 ;i<n; i++) { 

		if ( diffs[i] >= 0 ) {
			set< pair<int, int> > :: iterator it = neg.upper_bound( {i, -1 }); 
			while ( it != neg.end() ) {  // is it?
				if ( - (*it).second < diffs[i] ) 
					resp +=1; 
				it ++;  
			}
			if ( diffs[i] != 0 ) 
				resp += tots[i] -1 ;
			else 
				resp += tots[i] - zs[i]; 
		}
		else { 
			set< pair<int, int> > :: iterator it = pos.upper_bound( {i, -1 }); 
			while ( it != pos.end() ) { 
				if( - (*it).second < diffs[i] ) 
					resp +=1; 
				it ++ ; 
			}	
		}
	}

	cout<<resp<<endl; 

}

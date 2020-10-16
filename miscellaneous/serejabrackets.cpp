#include<iostream> 
#include<stdio.h> 
#include<stack> 
#include<vector> 
#include<algorithm> 
#include<string.h> 

using namespace std ;

const int MAXN = 1000000; 
const int MAXM = 100000; 

int resp[MAXM] ; 
char wd[MAXN] ; 
stack< pair<char, int> > pts; 
vector<pair<int, int>> rng; 

int espBs (int el, int p, int q ) { 
	int mid = p + (q-p+1)/2 ;

	if ( q >= p ) { 
		if ( rng[mid].first > el ) 
			return espBs(el, p, mid - 1 ) ; 
		else { 
			if ( rng[mid].first == el ) 
				return mid; 
			return espBs(el, mid + 1, q ) ; 
		}
	}

	return q; 
}

int qry(int i, int j , int size) { 
	int x = espBs(i, 0, size), y = espBs(j, 0, size) ;
	cout<<"i: "<<i<<" x: "<<x<<" j: "<<j<<" y: "<<y<<endl;

	if ( rng[x].first != i ) // since bs returns "lb" when search fails (??) turn into "ub"
		x += 1; 

	int cnt = y-x; 
	
	for(int k=x; k<y; k++) 
		if ( rng[k].second > j ) 
			cnt -=1 ;
	return cnt ; 
}

int main() { 
	int n, m; 

	scanf("%s",wd); 

	n = strlen(wd);

	pts.push({ wd[0], 0 } ); 

	for(int i=1; i<n; i++) {
		if ( wd[i] == ')') {
			if ( !pts.empty() && pts.top().first == '(' ) {
				rng.push_back( { pts.top().second, i } ) ; 
				pts.pop();
			}	
		}
		else  
			pts.push( {wd[i], i } ) ; 
	}// should I clear the stack ?

	sort( rng.begin(), rng.end() ) ; 

	for(pair<int, int> el : rng ) 
		cout<<el.first<<" "<<el.second<<endl; 


	cin >> m ;

	int k = m , u, v; 
	while ( k -- ) { 
		cin >> u>> v; 
		resp[ m-k-1 ] = qry(u-1, v-1 , n-1) ; 	
	}		

	for(int i=0 ;i<m; i++) cout<<resp[i]<<endl; 


//	cout<<espBs(4,0, rng.size() )<<endl ; 
}

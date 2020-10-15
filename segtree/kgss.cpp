#include<iostream> 
#include<stdio.h> 
#include<math.h> 
#include<vector> 
#include<utility> 

using namespace std; 

const int MAXN = 100000; 
const int MAXEXP = 1<<(ilogb(MAXN) + 2) ;
const int MAXINT = 0x7fffffff;

int a[MAXEXP]  ; 
vector<int> resp; 

void build(int size) { // receives best fit for n
	for(int k = size ; k > 0 ; k--)  
		for(int i = (1<<k) - 1 ; i < (1<<(k+1)) - 1; i += 2) 
			a[ (i-1)/2 ] = max(a[i], a[i+1]); 
}

void upd(int ind) {
	if ( ind > 0 ) { 
		a[ (ind-1)/2 ] = (ind%2 == 0 ) ? max(a[ind-1], a[ind]) : max(a[ind],a[ind+1]); 
		upd( (ind-1)/2 ); 
	}	
}  

void chg(int ind, int el , int size) { // receives best fit for n 
	int pos = (1<<size) - 1 + ind ; 

	a[ pos ]  = el ;
	upd( pos ) ; 
}

pair<int, int>  segment(int u, int v, int exp) { // receives best fit for n
	int i = (1<<exp) - 1 + u, j = (1<<exp) - 1 + v ; 
	int mx , current = i, cc, imp, ind, pp, rec; 

	mx = a[i], pp = i;   // keep record of maximum index on tree

	if ( a[i] % 2 ==0 ) 
		current +=1 ;

	while ( current < j ) { 
		ind = rec = current, cc = 0, imp = a[current]; 

		while ( ind % 2 == 1 && current + (1<<cc) < j ) { 
		
			imp = a[ (ind-1)/2 ]  ;
			rec = ind ; // ###

			ind = (ind-1)/2; 
			cc +=1; 
		}

		current += (ind != current) ? 1<<(cc-1) : 1; 

		if ( imp > mx ) { 
			mx = imp; 
			pp = rec; 	// ###
		}

		mx = max(mx, imp ); 
	}

	if ( a[j] > mx ) { 
		mx = a[j]; 
		pp = j; // ###
	}

	return {mx, pp } ; 
}

int findLeave(int ind , int exp) { // receives best fit for n
	while ( (ind +1)*2 - 1 < (1<<(exp+1)) - 1 )  
		ind = (ind + 1) * 2 - 1 ;

	return ind - ((1<<exp)-1);  
}

int main() { 
	int n, exp, q, u, v; 
	char let; 

	cin >> n; 

	exp = ilogb(n) + 1 ; // this is the power of 2 in wich n fit, (1<<(exp + 1)) - 1 is size of the heap 

	for(int i= (1<<exp) - 1 ;i< (1<<(exp+1)) - 1; i++)  	// get leaves
		if ( i < (1<<exp) - 1 + n) 
			cin >> a[i] ; 
		else
			a[i] = -1; 

	// agh
	build(exp); 						// build segtree

	cin >> q ;

	int t = q;  

	pair<int, int> fst, snd; 
	int son; 
	while ( t-- ) { 					// answer queries
		cin >> let >> u >> v; 
		if ( let == 'Q' ) {
			fst = segment( u-1, v-1, exp ) ; 	// find max and index
			son = findLeave (fst.second, exp ) ;	// find actual max index 

			chg ( son,  -1 , exp ); 		// change index entry 
			snd = segment ( u-1, v-1 , exp ) ; 	// find second max
			chg( son, fst.first, exp ) ; 		// restablish index 


			resp.push_back( fst.first + snd.first ) ; 
		}
		else 
			chg(u-1, v, exp ); 
	}
	// 
	
	for(int el : resp ) cout<<el<<endl; 
}

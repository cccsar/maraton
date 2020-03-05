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


const int TCASES = 1000;
const int MATMAX = 100;
const int WSIZE = 10; 

bool resp[TCASES];
char letters[MATMAX][MATMAX];
const char* ALLIZZWELL = "ALLIZZWELL";

void successors(vii &suc,  int i, int j , int width, int height) { 
	pi help;

	if ( i != 0 ) { 
		help.first = i-1; 
		help.second = j;  
		suc.push_back( help ) ; 
	}
	if ( i != height - 1 )   {
		help.first = i + 1 ;
		help.second = j; 
		suc.push_back( help );
	}
	if ( j != 0 ) {
		help.first = i; 
		help.second = j - 1;
		suc.push_back( help ); 
	}
	if ( j != width - 1 ) { 
		help.first = i ; 
		help.second = j + 1;
		suc.push_back( help );
	}

	if( i != 0 && j != 0 ) {
		help.first = i-1; 
		help.second = j-1; 
		suc.push_back( help );
	}
	if( i != 0 && j != width - 1)  {
		help.first = i - 1;
		help.second = j + 1;
		suc.push_back( help ); 
	}
	if( i != height - 1 && j != 0 ) {
		help.first = i + 1;
		help.second = j - 1;
		suc.push_back( help );
	}
	if ( i!= height - 1 && j != width - 1){
		help.first = i + 1;
		help.second = j + 1;
		suc.push_back( help );
	}

}


bool traversing(int i, int j, int height, int width, int index) { 
	vii surr; 
	bool guard; 

	guard = false; 

	successors(surr, i, j, height, width); 

	for(pi succ: surr ) { 
		if( letters[ succ.first ][ succ.second ] == ALLIZZWELL[ index ] ) {  

			cout<<letters[ succ.first ][ succ.second ]<<" "<<ALLIZZWELL[ index ] ;
			//cout<<succ.first<<" "<<succ.second<<endl;
			//if letter equals following, then if not the last, call to check
			//	next letter with new matrix indexes
			//otherwise 
			//	return true 
			if ( index == WSIZE - 1)
				return true; 

			guard = traversing( succ.first, succ.second, height, width, index + 1); 	

			if ( guard ) 	//if the call returned true, skip traverse
				break; 
		}
		cout<<endl;
	}

	return guard; 

}


int main() 
{
	int t, r, c, i_, j_, k_; 
	char letra[MATMAX]; 
	vii begins; 	
	pi dummie; 



	ri(t); 

	for (i_=0 ; i_<t ; i_++) { 

		rii(r, c);		
		for (j_=0 ; j_<r ; j_++) { 

			scanf("%s", letra); 
			for (k_=0 ; k_<c ; k_++) { 

				letters[j_][k_] = letra[k_];

				if ( letra[k_] == 'A' ) { 
					dummie.first = j_; 
					dummie.second = k_; 

					begins.push_back(dummie); 
				}
			}	
		}	

		//for(j_=0; j_<r ; j_++) {
		//	for(k_=0; k_<c ; k_++) {
		//		cout<<letters[j_][k_]; 
		//	}		
		//	cout<<endl; 
		//}

		for(pi source : begins )  {
			resp[i_] = traversing(source.first, source.second, r, c, 1); 

			if (resp[i_])
				break; 		
		}	


		begins.clear(); 	//clear pair vect
	}

	for(i_=0; i_<t ; i_++) 
		(resp[i_])? cout<<"YES"<<endl : cout<<"NOT"<<endl; 	
	
	return 0; 
}

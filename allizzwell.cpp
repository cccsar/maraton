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
#include<unordered_map>

using namespace std; 

#define FOR(i ,u ,l) for(i=l; i<u; i++) 
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
const int SSIZE = 6; 

const char* ALLIZZWELL = "ALLIZZWELL";
const char* WORD = "AEILWZ";

bool resp[TCASES];
char letters[MATMAX][MATMAX];

void successors(vector< vector< bool > > visited, vii &suc,  int i, int j , int height, int width) { 
	pi help;

	if ( i != 0 && !visited[i-1][j]) { 
		help.first = i-1; 
		help.second = j;  
		suc.push_back( help ) ; 
	}
	if ( i != height - 1 && !visited[i+1][j])   {
		help.first = i + 1 ;
		help.second = j; 
		suc.push_back( help );
	}
	if ( j != 0 && !visited[i][j-1]) {
		help.first = i; 
		help.second = j - 1;
		suc.push_back( help ); 
	}
	if ( j != width - 1 && !visited[i][j+1]) { 
		help.first = i ; 
		help.second = j + 1;
		suc.push_back( help );
	}

	if( i != 0 && j != 0 && !visited[i-1][j-1]) {
		help.first = i-1; 
		help.second = j-1; 
		suc.push_back( help );
	}
	if( i != 0 && j != width - 1 && !visited[i-1][j+1])  {
		help.first = i - 1;
		help.second = j + 1;
		suc.push_back( help ); 
	}
	if( i != height - 1 && j != 0 && !visited[j+1][j-1]) {
		help.first = i + 1;
		help.second = j - 1;
		suc.push_back( help );
	}
	if ( i!= height - 1 && j != width - 1 && !visited[i+1][j+1]){
		help.first = i + 1;
		help.second = j + 1;
		suc.push_back( help );
	}

}


bool traversing(vector< vector< bool> > visited, int i, int j, int height, int width, const int index) { 
	vii surr; 
	bool guard; 
	int j_, k_; 

	guard = false; 

	successors(visited, surr, i, j, height, width); 
	
	for(pi succ: surr ) { 
		if( letters[ succ.first ][ succ.second ] == ALLIZZWELL[ index ] ) {

			visited[ succ.first ][ succ.second ] = true; 
			//if letter equals following, then if not the last, call to check
			//	next letter with new matrix indexes
			//otherwise 
			//	return true 
			if ( index == WSIZE - 1)
				return true; 

			guard = traversing(visited, succ.first, succ.second, height, width, index + 1); 	

			if ( guard ) 	//if the call returned true, skip traverse
				break; 
		}
	}

	return guard; 

}


void setUpdate(unordered_map<char, int> &letter_set, char letter){

	if ( letter_set.count( letter ) != 0 )  
		letter_set[ letter ] += 1;
}
	

bool setCheck(unordered_map<char, int> letter_set) { 
	
	for(pair<char, int> k: letter_set ) { 
		if ( k.first == 'Z' ) {
			if ( k.second < 2 ) 
				return false; 
		}
		else if ( k.first == 'L' ) { 
			if ( k.second < 4 ) 
				return false; 
		}
		else if ( k.second == 0 ) {
		       return false; 
		}	       
	}

	return true; 
}


int main() 
{
	int t, r, c, i_, j_, k_; 
	char letra[MATMAX]; 
	vector< vector<bool> > visited; 
	unordered_map<char, int> letter_set; 
	vii begins; 	
	pi dummie, help; 


	for(i_=0; i_<SSIZE ; i_++) 
		letter_set[ WORD[i_] ] = 0; 

	visited.resize(MATMAX); 
	for(i_=0; i_< MATMAX ; i_++) 
		visited[i_].resize( MATMAX ) ;		


	ri(t); 
	for (i_=0 ; i_<t ; i_++) { 

		
		rii(r, c);		
		for (j_=0 ; j_<r ; j_++) { 

			scanf("%s", letra); 
			for (k_=0 ; k_<c ; k_++) { 

				letters[j_][k_] = letra[k_];
				setUpdate(letter_set, letra[k_] ) ; 

				if ( letra[k_] == 'A' ) { 
					dummie.first = j_; 
					dummie.second = k_; 

					begins.push_back(dummie); 
				}
			}	
		}	


		if ( !setCheck( letter_set ) ) {	//if not all letters then avoid traversing
			resp[i_] = false; 
		}
		else {
			for(pi source : begins )  {
				resp[i_] = traversing(visited, source.first, source.second, r, c, 1); 
	
				if (resp[i_])
					break; 		
			}	
		}


		begins.clear(); 	
		for(j_=0; j_<SSIZE ; j_++) 
			letter_set[ WORD[j_] ] = 0; 

	}


	for(i_=0; i_<t ; i_++) 
		(resp[i_])? cout<<"YES"<<endl : cout<<"NO"<<endl; 	
	

	return 0; 
}

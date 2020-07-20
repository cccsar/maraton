#include<stdio.h> 
#include<set> 
#include<vector>
#include<utility> 
#include<cmath> 

using namespace std; 

const int MAXS = 4*100000; 

typedef pair<int, int> ii; 

void foo(set<int> &factors ) { 
	
}
int main() { 
	int n ,r ; 
	set<int> uniq; 
	vector<ii> fact; 

	scanf("%d",&n); 

	for (int i=0; i<n; i++) { 
		scanf("%d",&r); 
		uniq.insert(r); 
	}

	int imp = *uniq.begin(); 	//catch minium
	uniq.erase(uniq.begin()); 

	if (imp == 1) 
		printf("%d\n",1 ) ; 
	else { 

		int p = imp; 
		int cnt ; 
		for (int i=2; i*i<=p; i++) { 
			cnt = 0; 
			if (p%i == 0 ) { 
				while ( p%i == 0 ) { 
					p /= i; 
					cnt += 1; 
				}
				fact.push_back( { i, cnt} ) ; 
			}	
		}	
	
		if ( p != 1) 
			fact.push_back( {p, 1} ) ; 			//factorize it
		
		
		int pp = 1, i, j,help = 0; 
		bool guard = true;
		for (i=0; guard && i<fact.size() ;i++)  
			for (j=1; j<=fact[i].second; j++) { 
	
				cnt = 0; 
				for (int k: uniq ) { 			//check if divisible by all
					if ( k%(imp-pp) ) 		//check this
						break ;
					cnt += 1; 
				}
				
				if ( cnt == uniq.size() ) {
					guard = false; 
					break; 
				}
	
				pp *= fact[i].first; 
			}
		i-=1; 

			

	
		printf("%d\n", acc); 
	}	
}

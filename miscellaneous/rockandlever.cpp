#include<stdio.h> 
#include<iostream> 
#include<math.h> 
#include<vector>
#include<map> 

using namespace std; 

vector<long long>  resp ; 
map<int, long long> logs; 

int main() {
	int t, n, dum;  
	long long acc; 

	cin >> t; 

	while ( t -- ) { 
		scanf("%d", &n); 


		// algorithm starts on read time

		for(int i=0 ;i<n; i++) { 
			scanf("%d",&dum); 
			logs[ ilogb( dum ) ] +=1; 
		}

		acc = 0;
		
		for(pair< int, long long>  el : logs )  
			if ( el.second > 1 ) 
				acc += ( el.second * ( el.second - 1) )  / 2; 

		// 

		resp.push_back ( acc ); 
		
		logs.clear(); 
	}

	for(long long el :  resp )  
		cout<<el<<endl; 
}

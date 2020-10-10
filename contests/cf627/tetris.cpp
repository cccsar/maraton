/*
 * https://codeforces.com/contest/1324/problem/A
 * cccsar
 */
#include<iostream> 
#include<stdio.h>
#include<vector> 

using namespace std; 

vector<bool> resp; 

const int MAXS = 100;

int main() 
{
	int t ,n; 
	int tet[MAXS], even, odd; 

	cin >> t;  
	while(t--) {
		even = odd = false;

		cin >> n; 
		for(int i=0; i<n ; i++) {
			cin>>tet[i]; 
			(tet[i] % 2 == 0)? even = true: odd = true; 
		}	
		
		resp.push_back( even & odd ); 
	}

	for(bool el : resp) el ? cout<<"NO"<<endl : cout<<"YES"<<endl ; 
}

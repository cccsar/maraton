#include<iostream> 
#include<vector> 
#include<algorithm>
#include<iterator>
#include<utility>

using namespace std; 

int main() 
{ 
	vector< pair<int, int> > v; 
	int n; 
	cin>>n; 

	for(int i=0; i<n; i++) {
		v[i].first = i; 
		v[i].second = n-i; 	
	}

	vector< pair<int, int> >::iterator it; 	

	for(it=v.begin(); it!=v.end(); it++) {  
		cout<<*it.first<<" "<<*it.second<<endl;;  
	}


	return 0; 
}

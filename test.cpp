#include<iostream> 
#include<string> 
#include<vector>

using namespace std; 

#define NUM 5 

int main() 
{
	vector<int> a; 
	int b ;

	for (int i=0; i<NUM; i++) { 
		cin>>b;
		a.push_back(b);
	}

	for(int x:a)
		cout<<x<<endl;

	return 0;
}






















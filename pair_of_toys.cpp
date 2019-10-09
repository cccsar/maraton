#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

int main() 
{
	long long n,k ;
	cin>>n>>k; 

	if (n+(n-1) < k) 
	{
		cout<<0<<endl; 
	}
	else if (n+1<k && k<=n+(n-1))
	{
		cout<< (k-1)/2 - (k - (n+1)) <<endl; 	
	}	
	else { 
		cout<< (k-1)/2 <<endl; 
	}
	
	return 0; 
}

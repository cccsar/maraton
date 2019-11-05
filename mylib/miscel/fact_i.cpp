#include<iostream> 

using namespace std; 

unsigned long long fact_r(int x) { 
	unsigned long long r = 1; 
	
	while (x != 0) { 
		r *= x; 
		x--; 
	}
	
	return r; 
}

int main() 
{
	int c; 
	cin>>c; 
	
	cout<<fact_r(c)<<endl; 

	return 0; 
}



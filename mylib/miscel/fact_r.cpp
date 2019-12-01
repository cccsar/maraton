
#include<iostream> 
#include<climits> 

using namespace std; 

unsigned long long fact(int x) {
	unsigned long long r = x;
		
	if (x == 1) 
		return x ; 
	else if (x > 1)
		r = r * fact(x-1);
}

int main() {
	int c;
	cin>>c; 
	
	cout<<fact(c)<<endl; 

	return 0 ;
}



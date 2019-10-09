
#include<iostream> 

using namespace std; 

unsigned long long fact(int x); 

int main() {
	int c;
	cin>>c; 
	
	cout<<fact(c)<<endl; 

	return 0 ;
}

unsigned long long fact(int x) {
	unsigned long long r = x;
		
	if (x == 1) 
	{	
		return x ; 
	}
	else if (x > 1)
	{
		r = r * fact(x-1);
	}

}


#include<iostream> 

using namespace std; 

int fibo (int x) { 
	int n = 0 ; 

	if (x == 0) 
	{ 
		return 0;
	}	
	else if (x == 1) 
	{
		return 1; 
	}
	else if (x > 1) 
	{ 
		n += fibo(x-1) + fibo(x-2) ; 	
	}
}

int main()
{
	int c; 
	cin>>c; 

	cout<<fibo(c)<<endl; 

	return 0 ; 
}
	
	


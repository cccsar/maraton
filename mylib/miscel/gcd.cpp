#include<iostream> 
#include<stdio.h>

using namespace std; 

int gcd(int n, int m) { 

	if(n==0 || m==0) 
		return max(n,m); 
	else if (n==1 || m==1)
		return 1; 

	return gcd( min(m,n), max(m,n)%min(m,n) ); 
}

int main() 
{
	int a,b ;
	scanf("%d %d", &a, &a); 

	cout<<gcd(a,b)<<endl;

	return 0; 
}

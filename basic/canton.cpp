
#include<iostream> 
#include<stdio.h> 
#include<math.h>
#include<string> 
	
using namespace std; 


int main() 
{
	int t;
	cin>>t; 
	long den[t], num[t], req[t];

	long c, acum; 
	for (int i=0; i<t; i++) { 
		
		cin>>req[i]; 	
		c = acum = 0;
		while(acum<req[i]) 
		{
			c++; 
			acum += c;
		}
		
		den[i] = (c%2==0)?  (acum-req[i]) + 1: c - (acum-req[i]) ; 
		num[i] = (c%2==0)? c - (acum-req[i]) : (acum-req[i]) + 1;  
	}

	for(int j=0; j<t; j++) { 
		cout<<"TERM "<<req[j]<<" IS "<<num[j]<<"/"<<den[j]<<endl; 
	}
	
	return 0; 
}


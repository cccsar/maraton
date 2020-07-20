
#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

int main() 
{
	int resp[1000]; 
	int T, n, s, t; 
	cin>>T; 

	for(int c=0; c<T; c++) {
	
		cin>>n>>s>>t; 
		if (n == s+t)
		{
			resp[c] = (s>t)? s + 1: t + 1; 
		}
		else { 
			int uni_s_t = (t + s) - n; 
			int a = t - uni_s_t; 
			int b = s - uni_s_t; 
			
			resp[c] = (a>b)? a + 1: b + 1; 
		}	
	}

	for (int i=0; i<T; i++) {
		cout<<resp[i]<<endl; 
	}

	return 0; 
}

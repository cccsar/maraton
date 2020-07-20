#include<iostream> 
#include<stdio.h> 
#include<math.h>
#include<string> 
	
using namespace std; 
 
int reverse(int number);
 
int main() 
{
	int resp[10000]; 
	int n, a, b, temp; 
	cin>>n; 
	
	for (int i=0; i<n; i++) {
		cin>>a>>b; 
		temp = reverse(a) + reverse(b); 
		resp[i] = reverse(temp);
	}
			
	for(int j=0; j<n; j++) { 
		cout<<resp[j]<<endl; 
	}
	
	return 0; 
}
 
int reverse(int number){
 
	if (number<10)
	{
		return number; 
	}
 
	int aux, c, digit;
	aux = c = 0;
 
	int stop = ceil( log10(number) ); 
	stop += (number/pow(10,stop)==1)? 1: 0; 
		
	stop--;
 
	while (stop!=-1)
	{
		digit = floor(number/pow(10,stop));
		aux += digit*pow(10,c);
		number -= digit*pow(10,stop); 	
		stop--;
		c++;
	}
	
	return aux; 
}

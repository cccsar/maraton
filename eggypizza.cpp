
#include<iostream> 
#include<stdio.h> 
#include<string> 
	
using namespace std; 

int reusable(int n) { 

	if ( n>=4 )
	{
		n = (n%4!=0)? n/4 + 1: n/4;
	}
	
	return n; 
}

int main() 
{
	int quarter = 0, half = 0, t_quarters = 0; 
	int n;
	cin>>n; 
	string aux; 
	
	for (int c=0; c<n; c++) { 
	
		cin>>aux; 
		if (aux=="1/4") 
		{
			quarter++;
		}
		else if (aux=="1/2") 
		{
			half++; 
		}
		else {
			t_quarters++; 
		}			
	}

	int response; 
	if (quarter>0 && half>0)
	{
		if (t_quarters>0) 
		{
			quarter = (quarter > t_quarters)? quarter - t_quarters: 0;
		}

		if (half%2 == 1 )
		{
			if (quarter%4 <= 2) 
			{
				quarter -= quarter%4; 
				half++;
			}
		}
			
		half = half/2; 

		quarter = reusable(quarter); 
	}
	else if (quarter>0 && half!=0 && t_quarters>0)
	{
		quarter = (quarter > t_quarters)? reusable(quarter - t_quarters): 0;
	}
	else if ( (quarter==0 && half>0 && t_quarters>0) || (quarter==0 && half>0 && t_quarters==0) )
	{
		half = (half%2 == 0)? half/2: half/2 + 1; 
	}
	else if (quarter>0 && half==0 && t_quarters==0)
	{
		quarter = reusable(quarter); 
	}

	response = quarter+half+t_quarters + 1;
	cout<<response<<endl; 
	return 0; 
}

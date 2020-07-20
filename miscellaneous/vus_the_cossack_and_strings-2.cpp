
#include<iostream> 
#include<string>
#include<bitset>

using namespace std; 


int main() 
{
	string f,s;
	cin>>f>>s; 

	int n,m,diff; 
	n = f.size(); 	
	m = s.size(); 
	diff = n-m;

	bitset<1000000> a(f);
	bitset<1000000> b(s);
	bitset<1000000> c; 	
	int count;
	int tot = 0;
	for (int i=0; i<=diff; i++) { 
		
		c = a^b; 	
		count = 0; 
		for (int j=i; j<i+m; j++) { 
		
			if (c[j] == 1)
			{	
				count++; 
			}
		}

		if (count%2 == 0)
		{
			tot++; 
		}

		b<<=1;
	}
	
	cout<<tot<<endl; 
	return 0; 
}


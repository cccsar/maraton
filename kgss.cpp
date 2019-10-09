
#include<iostream> 
#include<stdio.h> 
#include<vector>
#include<algorithm> 
#include<queue>
	
using namespace std; 

int max_sum(vector<int> s, int a, int b) 
{
	priority_queue<int> help ;

	for(int i=a-1; i!=b; i++) { 
		help.push( s[i] ); 
	}
	
	int p, q; 
	p = help.top(); 
       	help.pop();	
	q = help.top(); 
	help.pop();	

	return p + q; 
}


int main() 
{
	int n, q; 
	vector<int> a; 
	a.reserve(100000);
	vector<int> resp; 
	resp.reserve(100000);
		
	cin>>n; 

	int aux; 
	for (int c=0; c<n; c++){
		cin>>aux; 
		a.push_back(aux); 
	}

	cin>>q; 
	char qt; 
	int x, y, d; 
	int count = 0;
	for (int r=0; r<q; r++)  {

		cin>>qt>>x>>y; 	
		if (qt == 'U')
		{
			a[x - 1] = y;
		}
		else { 
			d = max_sum(a,x,y); 
			resp.push_back(d);
			count++;
		}

	}

	for (int i=0; i<count; i++) { 
		cout<<resp[i]<<endl; 
	}
			
		
	return 0; 
}

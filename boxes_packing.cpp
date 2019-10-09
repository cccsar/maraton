#include<iostream> 
#include<vector>
#include<iterator>
#include<set>
	
using namespace std; 

int figure_out(vector<int> bundle, int n_, int m_, int k_, int i) { 

	int o_count, running, reminder; 
	o_count = running = 0;  
	reminder = m_; 

	//cout<<"---------------------------------"<<endl;
	while (true) { 

		running+=bundle[i];

		if (running > k_)
	       	{ 
			reminder--; 
			running = bundle[i]; 
		}

		(reminder != 0)? o_count++: o_count+=0; 	
		//cout<<"running: "<<running<<"\treminder: "<<reminder<<"\to_count: "<<o_count<<endl; 
		if (o_count==n_ | reminder==0)
		{
			break; 
		}

		i++; 
	}

	return o_count; 
}

int main() 
{
	vector<int> objects; 
	objects.reserve(200000); 
	set<int, greater<int> > resp; 	
	int n, m, k; 

	cin>>n>>m>>k; 

	int aux; 
	for(int c=0; c!=n; c++) {
		cin>>aux; 
		objects.push_back(aux); 
	}
	
	int c_ans; 
	int r = 0; 
	while(true) {
		c_ans = figure_out(objects, n-r, m, k, r); 
		
		resp.insert(c_ans); 	
		if (c_ans == n-r) 
		{
			break; 
		}

		r++;
	}

	set<int, greater<int> >::iterator d = resp.begin(); 
	cout<<*d<<endl; 


	return 0; 
}

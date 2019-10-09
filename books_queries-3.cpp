#include<iostream> 
#include<vector>
#include<iterator>
	
using namespace std; 

int main() 
{
	int shelve[200001]; 
	vector<int> resp; 

	int q, aux, r_count, l_count;
	char e; 
	r_count = l_count = 0; 

	cin>>q; 
	for(int c=0; c!=q; c++) { 
		
		cin>>e>>aux; 
		if(e == 'L')
		{
			l_count++; 
			shelve[aux] = -l_count;  
		}
		else if(e == 'R')
		{
			r_count++; 
			shelve[aux] = r_count; 
		}
		else{

			if (shelve[aux] > 0)
			{
				if (r_count-shelve[aux] < l_count+shelve[aux])
				{
					resp.push_back(r_count - shelve[aux]); 
				}
				else { 
					resp.push_back(l_count + shelve[aux] - 1);
				}
			}
			else { 
				if (l_count+shelve[aux] < r_count + -1*shelve[aux])
				{
					resp.push_back(l_count + shelve[aux]); 
				}
				else { 
					resp.push_back(r_count + -1*shelve[aux] - 1); 
				}
			}
		}
	}	

	vector<int>::iterator it; 

	for(it=resp.begin(); it!=resp.end(); it++) { 
		cout<<*it<<endl; 
	}


	return 0; 
}

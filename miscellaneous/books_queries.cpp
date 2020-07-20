#include<iostream> 
#include<vector> 	
#include<cmath> 

using namespace std; 

int main() 
{
	vector<int> shelve; 
	vector<int> resp; 
	int q; 

	cin>>q; 
	
	int l_count, r_count, r, run_l, run_r;  
	l_count = r_count = 0; 
	int aux; 
	char e; 
	bool s ; 
	for (int c=0; c<q; c++) { 
		
		cin>>e>>aux; 
		
		if (e == 'L')
		{
			shelve.push_back(-aux); 
			l_count ++ ;
		}	
		else if (e == 'R')
		{
			shelve.push_back(aux); 
			r_count++; 
		}
		else {
			r = run_l = run_r = 0 ;
			s = true; 
			while (true) { 
				
				if (shelve[r] > 0)
				{
					run_r++ ;
					s = true; 
				}
				else { 
					run_l++; 
					s = false; 
				}

				if ( abs(shelve[r]) == aux ) 
				{	
					break; 
				}	

				r++;
			}

			(s == true)? resp.push_back(r_count - run_r) : resp.push_back(l_count - run_l); 
			
		}
	}
	
	vector<int>:: iterator it ;

	for (it=resp.begin(); it!=resp.end(); it++) { 
		cout<<*it<<endl;
	}

	return 0; 
}

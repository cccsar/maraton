#include<iostream> 
#include<stdio.h> 
#include<deque> 
#include<vector>
#include<string> 
	
using namespace std; 

int main() 
{
	deque<int> shelve; 
	vector<int> resp; 
	int q; 
	cin>>q; 
	
	deque<int>:: iterator f_it; 
	deque<int>:: reverse_iterator r_it; 
	int aux, r_count, l_count, i, j; 
	char e; 
	bool s; 
	r_count = l_count = 0; 
	for(int c=0; c<q; c++) { 
		cin>>e>>aux; 

		if(e == 'L')
		{
			shelve.push_back(aux); 
			l_count++; 
		}
		else if (e == 'R')
		{
			shelve.push_front(aux); 
			r_count++; 
		}
		else {
			f_it=shelve.begin(); 
			r_it=shelve.rbegin(); 
			i = j = 0; 
			s = true; 
			while (true) {
				
				if (i < r_count)
				{
					if (*f_it == aux) 
					{ 
						s = true; 
						break ;
					}	
					f_it++; 
					i++; 
				}

				if (j < l_count)
				{
					if (*r_it == aux) 
					{ 
						s = false; 
						break ;
					}
					r_it++; 
					j++;
				}
			}	

			(s == true)? resp.push_back(i) : resp.push_back(j);
		}

	}

	vector<int>::iterator fin = resp.begin(); 

	for(fin=resp.begin() ; fin!=resp.end(); fin++) {
		cout<<*fin<<endl; 
	}

	return 0; 
}

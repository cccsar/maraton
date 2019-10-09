#include<iostream> 
#include<utility> 
#include<vector>
	
using namespace std; 

int knapsack(vector< pair<int, int> > &v_s,int n_objects, int size, int resp[]); 
pair<int, int>  max_pers(vector< pair<int, int> > &v_s, int prev_sz, int current_sz, int size); 

int main() 
{
	vector< pair<int, int> > knap; 
	int s,n; 
	
	cin>>s>>n; 
	knap.reserve(n);  

	int val,sz; 
	for (int k=0; k<n; k++) 
	{
		cin>>sz>>val; 
		
		knap[k].first = sz;
		knap[k].second = val; 	
	}

	int r_sizes[n+1]; 
	for (int l=0; l<n+1; l++) { 
		r_sizes[l] = -1; 
	}

	int max_sum = knapsack(knap, n, s, r_sizes);

	cout<<max_sum<<endl; 


	return 0; 
}

int knapsack(vector< pair<int, int> > &s_v, int n_objects, int size, int resp[])
{
	
	pair<int, int> aux_p;  
	int max_val, acum; 
	max_val = acum = 0; 	

	resp[0] = 0; 

	for(int c=1; c<n_objects+1; c++) { 

		aux_p = max_pers(s_v, resp[c-1], c, n_objects); 	

		if (aux_p.first+acum >= size) 
		{
			break; 
		}
		else { 
			if (aux_p.second != -1) 
			{
				resp[c] = aux_p.first; 
				acum += aux_p.first; 
				max_val += aux_p.second; 
			}
			else { 
				resp[c] = resp[c-1]; 
			}
		}
	}

	/*
	for(int r=0; r<n_objects+1; r++) { 
		cout<<resp[r]<<" | "; 
	}
	cout<<endl;
	*/

	return max_val;
}	

pair<int, int>  max_pers(vector< pair<int, int> > &s_v, int prev_sz, int current_sz, int size) 
{

	pair<int, int> resp; 
	int k, ind; 
	k = ind = -1; 

	for (int i=0; i<size; i++) { 

		if (s_v[i].first <= current_sz-prev_sz) 
		{
			if (k < s_v[i].second) { 
				k = s_v[i].second; 
				ind = i; 
			}
		}
	}


	if (k==-1 && ind==-1)
	{
		resp = make_pair(-1, -1); 	
	}
	else { 
		resp = make_pair(s_v[ind].first, k); 
		s_v[ind].second = -1; 
	}

	/*	
	cout<<"The max value returned is: "<<resp.second<<endl;
	for(int p=0; p<size; p++) { 
		cout<<"size[p]: "<<s_v[p].first<<" value[p]: "<<s_v[p].second<<endl; 
	}
	*/

	return resp; 
}

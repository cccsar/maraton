#include<iostream> 
#include<vector>
#include<list>
#include<iterator> 
#include<utility> 
	
using namespace std; 

#define MAX_GRAPH 100

vector< list<int> > students_l; 

typedef pair< list<int>::iterator, list<int>::iterator> itpr; 

void adyListInsert(vector< list<int> > &ady_l, int a, int b) { 
	
	ady_l[a].push_back(b); 
	ady_l[b].push_back(a); 
}


itpr adyListFind(vector< list<int> > &ady_l, int a, int b) { 

	list<int>::iterator it_a,it_b; 
	itpr resp; 

	resp.first = ady_l[a].end();
	resp.second = ady_l[b].end();

	for(it_a=ady_l[a].begin(); it_a!=ady_l[a].end(); it_a++) {

		if (*it_a == b)
		{
			resp.first = it_a; 
			break ;
		}
	}

	for(it_b=ady_l[b].begin(); it_b!=ady_l[b].end(); it_b++) {

		if (*it_b == a)
		{
			resp.second = it_b; 
			break ;
		}
	}

	return resp; 
}

void adyListDelete(vector< list<int> > &ady_l, int a, int b) { 

	itpr to_delete; 
	
	to_delete = adyListFind(ady_l, a, b); 

	if (to_delete.first!=ady_l[a].end() && to_delete.second!=ady_l[b].end()) 
	{
		ady_l[a].erase( to_delete.first ); 
		ady_l[b].erase( to_delete.second );
	}
		
}

int main() 
{
	int ns, nt; 
	list<int>::iterator it; 

	cin>>ns>>nt; 

	students_l.resize(ns);

	int i,x,y; 
	for(i=0; i<nt; i++) { 
		cin>>x>>y; 
		adyListInsert(students_l,x-1,y-1); 
	}


	int j, count, s_count; 
	bool cond; 
	vector< pair<int, int> > later_delete; 

	later_delete.resize(ns); 
	count = 0;	
	
	while (true) { 

		cond = false; 
		s_count = 0; 
		for(j=0 ; j<ns; j++)  {

			if (students_l[j].size() == 1) 
			{
				cond = true;

				later_delete[s_count].first = j; 
				later_delete[s_count].second = students_l[j].front(); 

				s_count++; 
			}	
				
		}

		if (cond == true) 
		{
			int p; 
			for(p=0; p<s_count; p++)  
				adyListDelete(students_l, later_delete[p].first, later_delete[p].second); 

			count++;

			later_delete.clear(); 
		}
		else 
			break;
	}


	cout<<count<<endl; 
	return 0; 
}


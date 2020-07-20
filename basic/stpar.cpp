
#include<iostream> 
#include<string> 
#include<stack>
#include<queue>
	
using namespace std; 

bool isPossible(queue <int>app_st);
bool isIncreasing(stack <int>some_stk);

int main() 
{
	string resp[100];
	int count=0;

	while (true)  {

		int c;
		cin>>c; 	
		if (c == 0)
		{
			break;
		}
		
		queue <int>perm; 
		int aux; 
		for (int i=0; i<c ; i++) {
			cin>>aux;
			perm.push(aux);
		}				

		if ( isPossible(perm) ) 
		{	
			resp[count] = "yes"; 
		}
		else { 
			resp[count] = "no";
		}
	
		count++;
	}

	for (int j=0; j<count; j++) {
		cout<<resp[j]<<endl; 
	}

	return 0; 
}


bool isPossible(queue <int>app_st) { 

	int next = 1; 	
	int n = app_st.size(); 
	stack <int>side_st;
	
	while ( !side_st.empty() || !app_st.empty() ) { 

		if ( !side_st.empty() && side_st.top() == next ) 
		{
			side_st.pop(); 
			next++; 
		}
		else { 
		
			if (app_st.front() == next) 
			{
				app_st.pop();
				next++; 
			} 
			else { 
				side_st.push( app_st.front() );
				app_st.pop();
				
				if ( !isIncreasing(side_st) ) 
				{
					return false; 
				}	
			}
		}
		
	}		

	return true;
}
	

bool isIncreasing(stack <int>some_stk) { 
	
	int n = some_stk.size();
	int arr[n];

	for (int i=0; i<n; i++) { 
		arr[i] = some_stk.top(); 
		some_stk.pop(); 	
	}

	for (int j=0; j<n-1; j++) { 
		
		if (arr[j] > arr[j+1]) 
		{	
			return false;
		}
	}
	
	return true;
}

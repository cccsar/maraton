
#include<iostream> 
#include<climits> 	

using namespace std; 

int cost[100][100] ;

int main() 
{
	int n,m, u_b, l_b, ans;

	cin>>n>>m; 
	
	int i,j; 
	l_b = INT_MIN; 
	for(i=0; i<n; i++) {

		u_b = INT_MAX; 
		for(j=0; j<m; j++) {
			cin>>cost[i][j]; 

			if (cost[i][j] < u_b) 
				u_b = cost[i][j]; 

		}

		if (u_b > l_b)
			l_b = u_b; 
	}
	
	cout<<l_b<<endl; 
					
	return 0; 
}

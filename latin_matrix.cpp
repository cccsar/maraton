#include<stdio.h> 
#include<set> 

using namespace std; 

const int MAXX = 100; 

int mat[MAXX+1][MAXX+1]; 
int resp[MAXX+1][3]; 

int main() { 
	int n, t; 
	scanf("%d",&t); 

	int cnt_col, cnt_row; 
	for (int i=0; i<t; i++) { 
		cnt_col = cnt_row = 0; 
		scanf("%d",&n); 

		for (int j=0; j<n; j++)  {
			set<int> help_row; 

			for (int k=0; k<n; k++) {
				scanf("%d",&mat[j][k]); 

				if ( j==k ) 
					resp[i][0] += mat[j][k];
				help_row.insert( mat[j][k] ); 
			}
			if ( help_row.size() != n ) cnt_row +=1; 
		}

		resp[i][1] = cnt_row;  
		
		for (int j=0; j<n; j++) {
			set<int> help_col; 

			for (int k=0; k<n; k++)
			       help_col.insert( mat[k][j] ); 

			if ( help_col.size() != n ) cnt_col +=1; 
		}

		resp[i][2] = cnt_col; 
	}

	for (int i=0; i<t; i++) 
		printf("Case #%d: %d %d %d\n",i+1, resp[i][0], resp[i][1], resp[i][2]); 	
}

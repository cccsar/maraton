#include<iostream> 
	
using namespace std; 

#define MAX_STATIONS 1000
bool trn[2][MAX_STATIONS]; 

int main() 
{
	int ns, as, i, j, buff;

	cin>>ns>>as;

	for(i=0; i<2; i++) { 
		for(j=0; j<ns; j++) { 
			cin>>buff; 
			trn[i][j] = ( buff )? true: false; 
		}
	}

	if (trn[0][0] == 1) { 
		
		if( trn[0][as-1] )
			cout<<"YES"<<endl; 
		else {
			if( trn[1][as-1] ) { 

				int k;
				bool found = false; 
				for(k=as; k<ns; k++) { 

					if ( trn[0][k] && trn[1][k] )
					{
						found = true; 
						break; 
					}
				
				}
					
				( found )? cout<<"YES"<<endl: cout<<"NO"<<endl;
			}
			else  
				cout<<"NO"<<endl;

		}
	}
	else  
		cout<<"NO"<<endl;
	
	return 0; 
}

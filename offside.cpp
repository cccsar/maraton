
#include<iostream> 
#include<string> 
#include<algorithm> 
	
using namespace std; 

bool isOffside(int A[], int size, int player_pos);
int myMin(int D[], int size);


int main() 
{
	char response[100]; 
	int count = 0;
	int a,b; 
	int attack[11],defense[11]; 

	while (true) {

		cin>>a>>b; 
		if (a==0 && b==0)
		{
			break;
		}

		for (int i=0; i<a; i++) { 
			cin>>attack[i]; 
		}

		for (int j=0; j<b; j++) { 
			cin>>defense[j]; 
		}
		
		int position = myMin(attack, a); 
		
		response[count] = ( isOffside(defense, b, position) ) ? 'Y': 'N'; 
		count++;
	}

	for (int l=0; l<count; l++) { 
		cout<<response[l]<<endl; 
	}	

	return 0; 
}


bool isOffside(int A[], int size, int player_pos) {
	
	sort(A,A+size); 
	
	if ( A[0]!=A[1] ) 
	{	
		if (player_pos<A[1] )
		{
			return true;
		}
	}
	else { 	
		if( player_pos<A[0] )	
		{	
			return true;
		}
	}

	return false; 
}

int myMin(int D[], int size) { 
	int aux = 10001; // input specification says the distance from goal line is up to 10000 so we're using a maxInt

	for (int k=0; k<size; k++) { 

		if (aux > D[k])
		{
			aux = D[k]; 
		}
	}

	return aux;
}


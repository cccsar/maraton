/*
 * https://codeforces.com/contest/1324/problem/B
 * cccsar
 */
#include<iostream> 
#include<stdio.h>

using namespace std; 

const int MAXINT = 0x7fffffff;

const int MAXS = 5000; 
const int MAXT = 100;

bool resp[MAXT] ; 
int times[MAXS+1], word[MAXS+1] ;

int main() 
{
	int t, n, c; 
	bool stat; 
	
	for(int i=0; i<MAXS ; i++)  
		times[i] = 0; 

	cin>>t; 
	c = t+1;

	while( c-- ) { 
		stat = false; 

		cin>> n; 
		for(int i=0; i<n ; i++) {
			cin>>word[i];
			times[ word[i] ] +=1 ;
		}	

		// agh

		for(int i=0; i<n ; i++) {
			if ( times[ word[i] ] <= 1) 
				continue; 
			
			if ( times[ word[i] ] == 2 && n > 2) {
				if ( word[i] != word[i+1] ) {
					stat = true; 
					break; 
				}
				i+=1; 
			}	
			else  if ( times[ word[i] ] > 2 ){
				stat = true; 
				break; 
			}
		}	
		//


		resp[t-c] = stat;  

		for(int i=0; i<n ; i++) 
			times[ word[i] ] = 0 ;
	}

	for(int i=0; i<t ; i++) 
		(resp[i])? cout<<"YES"<<endl : cout<<"NO"<<endl;

	return 0; 
}

#include<stdio.h> 
#include<iostream>
#include <queue> 

#define MAXN 2000
#define MAXM 27
#define MAX(a,b) a>b?a:b

using namespace std; 


priority_queue< pair<char, pair<int, int> > > myQ; 

char maxR[MAXN], minR[MAXN];
int rnk[MAXN], group[MAXN], dist[MAXN][MAXN];
char line[MAXM]; 

int find(int el) {
	int cc = el ;

	while ( cc != group[cc]) 
		cc = group[cc] ; 

	if ( cc != el ) 
		group[el] = cc;

	return cc;
}

void onion(int u, int v ) {
	int x = find(u), y = find(v); 

	if ( x != y ) { 
		if ( rnk[x] >= rnk[y] ) { 
			group[y] = x; 
			if (rnk[x] == rnk[y]) 
				rnk[x] +=1; 
		}	
		else 
			group[x] = y; 
	}
} 

int kruskal(int size) { 
	pair< char, pair<int, int> > help ; 
	int cnt = 0;
	int cc = 255; 

	while ( cnt != size - 1 && !myQ.empty() ) { 
		help = myQ.top(); 
		myQ.pop(); 

		if ( find(help.second.first ) != find ( help.second.second ) ) { 
			onion (help.second.first, help.second.second); 

			if ( help.first < cc ) // as edges are added to the MaxST, check the minimum weight
				cc = help.first ;
		}
		cnt +=1; 
	}

	return cc; 
} 

int distance(int x, int y) { 
	return MAX( abs( maxR[x] - minR[y]) , abs( maxR[y] - minR[x] ) ); 
}

int main () { 
	int n, m; 
	
	scanf("%d %d",&n,&m); 

	for(int i=0 ;i<n; i++) { rnk[i] = 0; group[i] = i;}

	int dumMin, dumMax;  
	for(int i=0 ;i<n; i++) { 
		scanf("%s",line); 

		dumMin = 255; 
		dumMax = -1; 
		for(int j=0; j<m; j++) { // compute minimum and maximum character on each line
			if ( line[j] > dumMax ) 
				dumMax = line[j]; 	

			if (line[j] < dumMin)
				dumMin = line[j]; 
		}
		minR[i] = dumMin; maxR[i] = dumMax; 
	}

//	cout<<"mins\n"; 
//	for(int i=0 ;i<n; i++) printf("%d ", minR[i]); 
//	cout<<endl; 
//	cout<<"maxs\n"; 
//	for(int i=0 ;i<n; i++) printf("%d ",maxR[i]); 
//	cout<<endl; 


	for(int i=0 ;i<n-1; i++)  
		for(int j=i+1; j<n; j++)
			myQ.push( { distance(i,j), {i, j} } ); 
	// O((n-1)*n/2) since we consider the complete graph

//	for(int i=0 ;i<n-1; i++)  
//		for(int j=i+1; j<n; j++){
//			printf("%d %d %d", i ,j, distance(i,j) ); 
//			cout<<endl; 
//		}
//
	printf("%d\n",kruskal(n)); 
}

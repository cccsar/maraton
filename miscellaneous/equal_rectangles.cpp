#include<stdio.h> 
#include<algorithm> 

const int MAXN = 100; 
const int MAXQ = 500; 

bool resp[MAXQ + 1]; 
int rect[4*(MAXN + 1)]; 

int main() {
	int q, n ;

	scanf("%d",&q); 

	for (int i=0; i<q; i++) { 
		scanf("%d",&n); 

		int upper = 4*n; 
		for (int j=0; j<upper; j++) scanf("%d",&rect[j]);
		std::sort(rect, rect + 4*n); 

		int area = rect[0]*rect[upper-1]; 

		int j; 
		bool jic = true ; 
		for ( j=0; j<upper/2; j+=2) 
			if( rect[j] == rect[j+1] && rect[upper-(j+1)] == rect[upper-(j+2)]) {
				if ( rect[j] * rect[upper-(j+1)] != area) {
					jic = false; 
					break; 	
				}
			}
			else 
				break; 
		
		resp[i] = (j*2==upper && jic)? true: false; 
	}

	for (int i=0; i<q; i++) (resp[i])? printf("YES\n"): printf("NO\n"); 



}

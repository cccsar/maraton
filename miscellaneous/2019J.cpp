#include<iostream> 

#define FOR(i,a,b) for(i=a; i<b; i++) 
#define ROF(i,a,b) for(i=a; i>b; i--) 
#define ri(c) scanf("%d",&c)
#define rii(c,cc) scanf("%d %d", &c, &cc)
	
using namespace std; 
bool resp[1000]; 

int main() 
{
	int t, qs, i, j, a, b; 

	ri(t); 
	FOR(i, 0, t) { 
		ri(qs); 

		if (qs > 2) { 
			ri(a); 
			FOR(j, 0, qs -1) {
				ri(b); 
				if (b-a == 1)  
					resp[i] = true; 

				a = b; 
			}
		}
		else if (qs == 2) { 
			rii(a,b); 
			resp[i] = (b-a == 1)? true: false; 
		}
		else  {
			ri(a); 
			resp[i] = false; 
		}
	}

	FOR(i, 0, t){ 
		if (!resp[i]) 
			printf("Case #%d: Survival!\n",i+1); 
		else
			printf("Case #%d: Oh no!\n",i+1); 
	}
}

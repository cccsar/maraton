#include<iostream> 

#define FOR(n) for(int i=0; i<n; i++) 
#define ROF(n) for(int i=n; i>0; i--) 
#define rint(c) scanf("%d",&c)
#define rints(c,cc) scanf("%d %d", &c, &cc)
#define rintt(c,cc,ccc) scanf("%d %d %d", &c, &cc, &ccc)
	
using namespace std; 

#define MAX_QUERIES 100

int resp[MAX_QUERIES];


int pairBS(int str, int intg, int exp) { 
	int a,b,c, count; 
	a = str + exp; 
	b = intg;
	c = exp+1 ;
	
	cout<<"a: "<<a<<" b: "<<b<<endl;
	while (a>b+1 || a<b-1) {

		c /= 2;
		if(a>b) { 
			a -= c; 
			b += c; 
		}
		else { 
			a += c; 
			b -= c; 
		}
		cout<<"a: "<<a<<" b: "<<b<<endl;
	}

	return (a == b)? str+exp-a: str+exp-max(a,b)+1 ;

}

int main() 
{
	int nq, str, intg, exp;
	
	rint(nq); 

	FOR(nq) { 
		rintt(str, intg, exp); 

		if (str > intg)  {
			resp[i] = (intg + exp < str)? exp + 1: pairBS(str, intg, exp) ;
		}
		else if (str == intg)  
			resp[i] = (exp+1)/2;
		else  
			resp[i] = (str+exp>intg)? pairBS(str, intg, exp): 0; 
		
	}

	FOR(nq) 
		cout<<resp[i]<<endl;

	return 0; 
}

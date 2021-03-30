#include<stdio.h> 
#include<vector> 

#define FOR(i,a,b) for(int i=a; i<b; i++) 
#define ROF(i,a,b) for(int i=a; i>b; i--) 

using namespace std ;

typedef vector<int> vi; 

const int MAXN = 10000000; 
int xd ; 

vi st(4*MAXN, 0) ; 
vi inp(MAXN, 0); 

int foo (int a, int b) {
    return a + b ;
}

int create (int l, int r, int curr) { 

    if ( l != r ) { // if not a leave, spawn computation of a binary operation 
                    // having as argument each subtre (l,r) result
        int mid = (l+r)/2; 
        return st[curr] = foo( create(l,mid,2*curr + 1) ,create(mid+1,r,2*(curr +1) ) ); 
    }

    return st[curr] = inp[l] ; 
}

int update (int l, int r,int x , int e, int curr ) { 
    if (l!=r)  {
        int mid = (l+r)/2; 

        /* Performs bs for x over bounds (l,r) choosing to call only the side where the 
         * x might be and maintain the result (st[..]) on the other side
         */
        if ( x <= mid )  
            return st[curr] = foo (update(l, mid, x, e, 2*curr + 1), st [2*(curr + 1) ] ) ; 
        return st[curr] = foo( update(mid+1,r,x,e, 2*(curr + 1)), st[2*curr + 1] ) ;
    }

    return st[curr] = inp[x] = e; 
}

int query (int l, int r, int p, int q, int curr) { 

    return 0 ;
}

int main() { 
   int n , t; 

   xd = scanf("%d\n", &n); 

   t = n; 
        
   while ( t-- ) xd = scanf("%d",&inp[n-t-1] );    

   //FOR(i,0,n) printf("%d ", inp[i]); 
   //printf("\n"); 

   // test stuff here
   create(0,n-1,0); // uwu

   update(0,n-1,3,19,0);  // uwu

   FOR(i,0,4*n) printf("%d ", st[i]); 
   printf("\n"); 
}

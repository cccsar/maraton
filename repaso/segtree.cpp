#include<stdio.h>
#include<iostream> 
#include<vector>
#include<stack> 
#include<queue> 
#include<algorithm> 

using namespace std; 

int uwu;

#define FOR(i,lb,ub) for(int i=lb ; i<ub ; ++i)
#define ROF(i,ub,lb) for(int i=ub ; i>lb ; --i) 
#define pb(el) push_back(el) 
#define ri(i) uwu = scanf("%d",&i)
#define rii(i,j) uwu = scanf("%d %d", &i, &j) 
#define rl(l) uwu = scanf("%lld",&l)
#define rll(l,m) uwu = scanf("%lld %lld",&l, &m) 
#define SZ(el) el.size()
#define fst first
#define snd second

const int MAXI = 0x7fffffff;

typedef pair<int, int> pi ; 
typedef pair<int, pi> pii; 
typedef vector<long long> vl; 
typedef vector<char> vc; 
typedef vector<bool> vb; 
typedef vector<int> vi; 
typedef vector<pi> vii; 

//GC


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

int query (int lb, int ub, int lo, int hi, int curr) { 
    if ( lo > hi ) 
        return 0 ;

    if (lb == lo && ub == hi) 
        return st[curr]; 
    else  { 
        int mid = (lb+ub)/2;
        return foo( query(lb,mid,lo, min(mid,hi),2*curr + 1) , query(mid+1,hi,max(mid+1,lo), hi, 2*(curr +1) ) )   ;
    }
}

int main() { 
   int n ; 

   ri(n); 

   FOR(i,0,n) ri(inp[i]); 

   create(0,n-1,0); // uwu

   FOR(i,0,4*n) printf("%d ",st[i]); 
   cout<<endl; 

   cout<<query(0,n-1,2,5,0) <<endl;

//   update(0,n-1,3,19,0);  // uwu

}

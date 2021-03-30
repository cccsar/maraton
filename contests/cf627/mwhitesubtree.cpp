/*
 * https://codeforces.com/contest/1324/problem/F
 * Maximum white subtree
 */
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
#define pb(el)  push_back(el) 
#define ri(i) uwu = scanf("%d",&i)
#define rii(i,j) uwu = scanf("%d %d", &i, &j) 
#define rl(l) uwu = scanf("%lld",&l)
#define rll(l,m) uwu = scanf("%lld %lld",&l, &m) 

const int MAXI = 0x7fffffff;

typedef pair<int, int> pi ; 
typedef pair<int, pi> pii; 
typedef vector<long long> vl; 
typedef vector<char> vc; 
typedef vector<bool> vb; 
typedef vector<int> vi; 
typedef vector<pi> vii; 

//GC

const int MAXS = 200000; 

vi *tree = new vi[MAXS]; 
int parent[2][MAXS], dp[2][MAXS], color[MAXS]; 

int dfs_prev(int r) { 
    int acc = 0; 

    for(auto son : tree[r]) 
        if (parent[0][son] == -1 ) { parent[0][son] = r; acc += dfs_prev( son ) ; }

    int xd = color[r] ? 1 : -1, xp = xd + acc; 

    if(xp >= 0) { dp[0][r] = xp;  return xp ; }

    dp[0][r] = -1; return 0; 
}

void dfs_post(int r) { 
    if ( dp[0][r] != -1 ) // if it wasn't ignored result is maximum between routing in parent or in current
        dp[1][r] = max( dp[0][r], dp[1][parent[0][r]] ) ; 
    else                 // it was ignored result depends on wether parent result can make current better
        dp[1][r] = (dp[1][parent[0][r]] > 0) ? dp[1][parent[0][r]] - 1 : -1 ;  

    for(auto son: tree[r]) 
        if (parent[1][son] == -1) { 
            parent[1][son] = r; 
            dfs_post(son) ; 
        }
}

int main() { 
   int n, u, v ;

   ri(n); 

   FOR(i,0,n)  parent[0][i] = parent[1][i] = -1; 

   FOR(i,0,n) ri(color[i]) ; 
   FOR(i,0,n-1) { 
       rii(u,v) ; 
       tree[u-1].pb(v-1); 
       tree[v-1].pb(u-1); 
   }

   parent[0][0] = parent[1][0] = 0; 
   dfs_prev(0); 

   dfs_post(0); 

   FOR(i,0,n) printf("%d ",dp[1][i] ); 
   printf("\n"); 
}

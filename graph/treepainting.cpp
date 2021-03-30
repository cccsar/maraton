/*
 * https://codeforces.com/contest/1187/problem/E 
 * Tree painting
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
#define pb(el) push_back(el) 
#define ri(i) uwu = scanf("%d",&i)
#define rii(i,j) uwu = scanf("%d %d", &i, &j) 
#define rl(l) uwu = scanf("%lld",&l)
#define rll(l,m) uwu = scanf("%lld %lld",&l, &m) 
#define SZ(e) (int)e.size()

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
int parent[2][MAXS], ss[MAXS], ttl[MAXS];

int dfs_prev(int r) { 
    int acc =0; 
    for(auto son: tree[r])
        if ( parent[0][son] == -1) { parent[0][son] = r; acc += dfs_prev(son); }
    return ss[r] = acc + 1; 
} // Just compute the size of subtrees rooted at each node of the dfs traversal

int dfs_post(int r, int sz) {
    // Add to new root total what makes it smaller from sz and 
    // substract what makes previous root bigger than it's new value
    // .. this leads to sz - 2*ss[r]
    if ( parent[0][r] != r) ttl[r] = ttl[ parent[0][r] ] + sz - 2*ss[r];
    int mx = ttl[r] ; 

    for(auto son : tree[r])
        if (parent[1][son] == -1) { 
            parent[1][son] = r; 
            mx = max( mx, dfs_post(son, sz) ) ; 
        }

    return mx; 
}

int main() {
    int n, u, v;
    ri(n);

    FOR(i,0,n) parent[0][i] = parent[1][i] = -1; 

    FOR(i,0,n) {
        rii(u,v);
        tree[u-1].pb(v-1);
        tree[v-1].pb(u-1);
    }


    parent[0][0] = parent[1][0] = 0; 
    dfs_prev(0); 

    int total = 0;
    FOR(i,0,n) total += ss[i];

    ttl[0] = total; 


    printf("%d\n",dfs_post(0,n));
}

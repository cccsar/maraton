#include<stdio.h> 
#include<vector> 
#include<utility> 
#include<queue>

using namespace std;

typedef pair<int,int> pi; 
typedef pair<int, pi> pii;
typedef vector<pi> wlady; 


const int MAXN = 10000000; 

wlady *graph = new wlady[MAXN]; 
int pops[MAXN]; 

int parent[MAXN]; 
int rnk[MAXN]; 

int fnd(int el) { 
    int dum = el ;

    while ( dum != parent[dum] ) 
        dum = parent[dum]; 

    return dum; 
}

bool unn(int x, int y) { 
    int u, v; 
    u = fnd(x); v = fnd(y); 

    if ( u != v )  {
        if ( rnk[u] <= rnk[v] ) {
            if ( rnk[u] == rnk[v] ) 
                rnk[v] +=1; 
            parent[u] = v; 
        }
        else  
            parent[v] = u; 
        

        return true; 
    }

    return false; 
}

void prim(int sz) { 
    priority_queue<pii> my_q; 
    int xd = sz; 

    while (xd--) 
        for(auto adj : graph[xd])
            my_q.push( { -adj.second, { xd, adj.first } } ); 

    int cnt = 0; 
    pii d; 

    while ( cnt != sz || !my_q.empty() ) {  
        d = my_q.top(); 
        my_q.pop(); 

        if ( unn(d.second.first,d.second.second) ) 
            cnt +=1; 
    }
}

// yet to test, I did it partially from memory

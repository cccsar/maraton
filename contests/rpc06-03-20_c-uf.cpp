#include<iostream> 
#include<vector> 
#include<queue> 
#include<math.h> 

using namespace std; 

int xd ;

#define FOR(i,p,q) for(int i=p; i<q; i++) 
#define ri(e) xd = scanf("%d",&e); 
#define rii(e,f) xd = scanf("%d %d",&e, &f); 
#define riii(e,f,g) xd = scanf("%d %d %d",&e, &f, &g); 

typedef vector<int> vi ; 
typedef pair<int, int> pi; 
typedef vector<pi> vii; 

const int MAXN = 1000; 

vi g1[MAXN], g2[MAXN]; 
vi pt, rk (MAXN,0); 

int join(int e) { 
    int d = e; 

    while ( d != pt[d] ) d = pt[d] ; 

    return d; 
}

bool find (int x, int y) { 
    int u, v; 
    u = join(x), v = join(y); 

    if ( u != v ) { 
        if ( rk[u] <= rk[v]) { 
            if (rk[u] == rk[v] )
                pt[v] = u; 
            rk[v] +=1; 
        }
        else 
            pt[u] = v; 

        return true; 
    }
    
    return false; 
}

float dist (pi a , pi b) { 
    return sqrt( pow(a.first - b.first,2) + pow (a.second + b.second,2) ) ; 
}

int main() {
    printf("%f\n", pow(2,3)); 
    return 0 ;
    int n,m, p ;
    vii goku, gohan, trunks; 

    riii(n,m, p); 

    pt.resize(n); 

    goku.resize(n); 
    gohan.resize(m); 
    trunks.resize(p); 

    FOR(i,0,n)  rii( goku[i].first, goku[i].second );   
    FOR(i,0,m)  rii( gohan[i].first, gohan[i].second );   
    FOR(i,0,p)  rii( trunks[i].first, trunks[i].second )  

    FOR(i,0,n) pt[i] = i ; 

    priority_queue<pair<float, pair<int, int>> > my_q; 
    float tot = 0.0; 

    FOR(i,0,n) 
        FOR(j,0,m) 
            my_q.push( { dist( goku[i], gohan[j] ), { i  , j + n }} ) ;


    int cnt = 0 ;
    while ( !my_q.empty() && cnt != n + m - 1) { 
        auto d = my_q.top(); 
        my_q.pop(); 

        if ( find ( d.second.first, d.second.second  ) ) {  // check if already on set
            tot += d.first ;
            cnt +=1 ;
        }
    }


    int u,v; 
    FOR(i,0,m) { 
        rii(u,v); 
        find(u,v); 
    }

    // tested and supossedly worked
    FOR(i,0,n) printf("%d ",pt[i]); 
    printf("\n");
    FOR(i,0,n) printf("%d ",rk[i]); 
    printf("\n"); 
}

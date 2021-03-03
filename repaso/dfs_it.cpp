#include<iostream> 
#include<stack> 
#include<vector> 

using namespace std; 

#define pb(e) push_back(e)
const int MAXS = 10000; 
typedef vector<int> lady; 

lady graph[MAXS]; 
bool vtd[MAXS]; 

void dfs(int r) { 
    stack<int> ra; 
    int d; 

    ra.push(r); 

    while ( !ra.empty() ) {
        d = ra.top(); 
        ra.pop(); 

        if ( !vtd [d] ) {  // a node in the stack might already have been visited
            vtd[d] = true; 
            printf("%d\n",d); 

            for (auto adj : graph[d] ) 
                if ( !vtd[adj] ) 
                    ra.push( adj ) ; 
        }
    }

}

int main(){ 
    int n, m, t, foo, bar; 

    scanf("%d %d",&n, &m); 

    t = m ;

    for(int i=0; i<n; i++) vtd[i] = false; 

    while ( t-- ) { 
        scanf("%d %d", &foo, &bar); 
        graph[foo].pb(bar);
        graph[bar].pb(foo);
    }

    dfs(0);

}

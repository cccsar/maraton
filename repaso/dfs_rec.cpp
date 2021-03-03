#include<iostream> 
#include<vector> 

using namespace std; 

#define pb( e ) push_back( e ) 

typedef vector<int> lady; 

const int MAXS = 100000; 
bool vtd[MAXS]; 
lady graph[MAXS]; 

void dfs_rec(int r) { 
    
    // just entered traversal

    printf("%d \n", r); 
    for (auto adj : graph[r] ) 
        if ( !vtd[adj] ) { // if an adjacent node hasn't been traversed, traverse it 
            vtd[adj] = true; 
            dfs_rec(adj) ; 
        }

    // finished subtree rooted at r
}

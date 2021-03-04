#include<iostream> 
#include<queue> 
#include<vector> 

using namespace std; 

const int MAXN = 100000; 
typedef vector<int> lady; 

int parent[MAXN]; 
lady graph[MAXN] ; 

void bfs( const int r) { 
    queue<int> xd; 
    int d; 

    xd.push(r); 
    parent[r] = r; 

    while ( !xd.empty() ) { 
        d = xd.front();  // get the next to check element as the one at the front, making it an
                        // inmediate descendant of the previously checked element or a same depth
                        // element of the previously checked element.
        xd.pop(); 

        for(auto adj : graph[d]) 
            if (parent[adj] == -1) {
                parent[adj] = d; 
                xd.push( adj ) ; 
            }
    }
}

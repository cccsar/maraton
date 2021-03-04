#include<stdio.h> 
#include<vector> 
#include<utility>
#include<queue>
#include<vector> 

using namespace std; 


const int MAXN = 100000;  
const int MAXINT = 0x7fffffff;

typedef pair<int, int> pi; 
typedef vector<pi> wlady; 


int cmin[MAXN]; 
wlady graph[MAXN]; 

void dijkstra(int r) { 
    priority_queue<pi> my_q; 
    pi d; 

    cmin[r] = 0; 
    my_q.push( {0, r} ) ; 

    while ( !my_q.empty() ) { 

        d = my_q.top(); 
        my_q.pop();

        /* Consider de undirected graph V = {0,1,2}, E = { (0,1,2), (0,2,1), (1,2,2) }
         * A cold of dijkstra would show the following behaviour:
         *
         * cmin = [0,INF,INF] -- my_q( {(0,0)} ) 
         * cmin = [0,2,1]     -- my_q( {(1,2), (2,1)} ) 
         * cmin = [0,2,1]     -- my_q( {(2,1)} )
         *
         *      At this point, while checking whether 
         *          cmin[ adj.first ] > d.first + adj.second .. cmin[ 1 ] > 1 + 2 .. False
         *      This apparently shows that once a cmin is assigned, is never rewritten. Otherwise, 
         *      if there was already a shorter path to adj.first, we would have already reached it.
         *      But what if there's a negative weighted edge??
         */ 
        if ( (-d.first) > cmin[ d.second ]) // check this
            continue; 

        for (auto adj : graph[ d.second ] ) 
            if ( cmin[adj.first] > (-d.first) + adj.second ) { 
                cmin[adj.first] = (-d.first) + adj.second; 
                my_q.push( { - cmin[adj.first], adj.first } ) ; 
            }

    }

}

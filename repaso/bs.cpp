#include<iostream> 
#include<algorithm> 
#include<cassert> 

#define MAXS 100000

using namespace std; 

int xd[MAXS];

/* Like always, remember that (l+r)/2 chooses the left middle when the space between l and r (uninclusive) is even.
 * Since middle is checked and discarded, displace it conveniently on further lookups
 */

int bs(int l, int r, int e)  {
    assert( l <= r || l == r + 1 );  // Selected displacement causes l == r + 1 on failed searchs

    if (l <= r) { 
        int mid = (l+r)/2; 
        if ( xd[mid] <= e) {
            if (xd[mid] == e) 
                return mid; 
            return bs(mid + 1, r, e) ; 
        }
        return bs(l, mid-1, e); 
    }
    return -1 ;
}

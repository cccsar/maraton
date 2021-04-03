/*
 * https://www.spoj.com/problems/GSS1/ 
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

const int MINN = -1508; 
const int MAXN = 50000; 
pii st[4*MAXN], inp[MAXN]; 

pii foo(pii l, pii r ) { 
    int mid = l.fst + r.fst + l.snd.snd + r.snd.fst ; 
    int mx = max( max( mid, l.fst), r.fst ) ; 

    if (mx == mid)  
        return { mid, {l.snd.fst, r.snd.snd } } ; 
    else if ( mx == l.fst ) { 
        return { l.fst, { l.snd.fst, l.snd.snd + r.snd.fst + r.fst + r.snd.snd } } ;  
    }

    return { r.fst, { l.snd.fst + l.fst + l.snd.snd + r.snd.fst, r.snd.snd} } ; 
}

pii st_create(int l, int r, int curr) { 
    if (l != r) { 
        int mid = (l+r)/2; 
        return st[curr] = foo( st_create(l,mid,2*curr+1) , st_create(mid+1,r,2*(curr+1)) ) ; 
    }
    return st[curr] = inp[l] ; 
}

pii st_query(int l, int r, int lo , int hi, int curr) { 
    if (lo > hi)  
        return {MINN, {MINN, MINN}} ; 

    if ( l == lo && r == hi ) 
        return st[curr]; 
    else { 
        int mid=(l+r)/2; 
        return foo( st_query(l,mid,lo, min(hi,mid),2*curr+1) , st_query(mid+1,r,max(mid+1,lo),hi,2*(curr+1)) ); 
    }

}

int main() { 
    int n, m, u,v , t;

    ri(n); 

    FOR(i,0,n) { 
        ri(t); 
        inp[i] = { t,{ MINN, MINN} } ; 
    } 
    st_create(0,n,0); 

    ri(m); 

    FOR(i,0,m){ 
        rii(u,v); 
        cout<< st_query(0,n,u-1,v-1,0).fst<<endl;  
    }


}

/*
 * minimum is non negative -> sum of all segment
 * maximum is negative -> maximum
 *
 * given a sum s for a segment, how to check it is greater/lesser than a sum for any of it subsequences?
 *
 * testcase:
 *  | 1 -1 8 -13 19 14 -2 -1 -3 -9 3 8 19 -17 | min = -17 ; max=19 ; sum=26 ; actual result = { i=4, j=12, r=48 } 
 *
 *   st_create(0,13,0) -> foo: { -5, 48, -17}   
 *     st_create(0,6,1) -> foo: { -5, 33, -2} 
 *       st_create(0,3,3) -> foo  : { 0, 8, -13 } 
 *         st_create(0,1,7) -> foo ;  { 0, 1, -1 + 0 } 
 *           st_create(0,0,15) -> {0, st[15] = a[0] = 1 , 0} 
 *           st_create(1,1,16) -> {0, st[16] = a[1] = -1, 0}
 *         st_create(2,3,8) -> foo : { 0, 8, -13 } 
 *           st_create(2,2,17) -> {0, st[17] = a[2] = 8, 0}
 *           st_create(3,3,18) -> {0, st[18] = a[3] = -13, 0}
 *       st_create(4,6,4) -> foo: {0,33,-2} 
 *         st_create(4,5,9) -> foo : { 0, 33 , 0}
 *           st_create(4,4,19) -> st[19] = a[4] = 19
 *           st_create(5,5,20) -> st[20] = a[5] = 14
 *         st_create(6,6,10) -> {0, st[10] = a[6] = -2, 0 }
 *     st_create(7,13,2) -> foo: {-13, 30, -17}
 *       st_create(7,10,5) -> foo : { -13, 3 , 0}
 *         st_create(7,8,11) -> foo : { 0, -1, -3 } 
 *           st_create(7,7,23) -> st[23] = a[7] = -1
 *           st_create(8,8,24) -> st[24] = a[8] = -3
 *         st_create(9,10,12) -> foo : { -9, 3, 0 } 
 *           st_create(9,9,25) -> st[25] = a[9] = -9
 *           st_create(10,10,26) -> st[26] = a[10] = 3
 *       st_create(11,13,6) -> foo { 0, 27, -17}
 *         st_create(11,12,13) -> foo { 0, 27, 0 } 
 *           st_create(11,11,27) -> st[27] = a[11] = 8
 *           st_create(12,12,28) -> st[28] = a[12] = 19
 *         st_create(13,13,14) -> {0, st[14] = a[13] = -17, 0} 
 *
 * problem with only a binary operation: 
 *  let foo be the binary operation over which the three is built. f
 *  foo produces a correct answer for any consecutive segment solutions it receives.
 *  let a and b be segments such that 
 *      b = A[i]..A[j] ^ i<j 
 *      a = A[p]..A[q] ^ p < q
 *      p = j + 1
 *  besides, let s and r be solutions to the maximization problem for a and b respectively.
 *  then foo(s,r) should give a solution for segment t = A[i]..A[q]
 *
 *  such a foo that produces a correct solution must consider:
 *      1) segmet associated to s might be a strict prefix for b, thus the remaining suffix must be carried out
 *      2) the same but for a suffix and a.
 *      3) solutions might not even include ends of the segment
 *  for the first two cases, as said, information concerning the remaining of the segment must be carried
 *  as part of the solution.
 *  the last case must include a case for the prefix and suffix it is not taking in count.
 *
 *  then , each element (segment) of the st must contain the following information for queries at any given moment
 *
 *  { pf , sol, sf } 
 *
 *  where pf = 0 v sf = 0 implies the solution is part of a suffix or a preffix for the segment in question.
 *
 *  when two segment are compared, care must be taken. For the same segments of the introductory example we have:
 *
 *  { pf_b, sol_b, sf_b } and { pf_a, sol_a, sf_a }
 *
 *  in order to produce a solution for t we consider:
 *      * sf_b == sf_a == 0 -> 
 *           sol_t = max(sol_b+sol_a,sol_b,sol_a) 
 *           (sol_t == sol_b+sol_a) ?pf_t=pf_b , sf_t=sf_a : adjust conveniently; 
 *        this is , if solutions are indeed 'consecutive', then compare them and their sum 
 *        (in case one or both are negative), their suffix remain
 *      * else -> 
 *          sol_t = max( sol_b +sf_b +pf_a+sol_a, pf_a + sol_a, sf_a + sol_b ) 
 *          sf_t and pf_t dependen del resultado
 */


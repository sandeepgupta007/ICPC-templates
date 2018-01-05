// sandeep_007	
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define vi vector < int >

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b){
    return (a.second < b.second);
}
 
inline ll mx(ll a,ll b){
	if(a > b) return a;
	else return b;	
}

// Segment tree
ll tree[4000000]={0};
ll lazy[4000000]={0};
// build(1,n,1,A);
void build(int s,int e,int nod_num,ll A[]){
	if(s == e){
		tree[nod_num] = A[s];
		return;	
	}
	int m = (s+e)/2;
	
	build(s,m,nod_num*2,A);
	build(m+1,e,nod_num*2+1,A);
	
	tree[nod_num] = tree[2*nod_num] + tree[2*nod_num+1];
	return;	
}

//updateRange(1,1,n,l,r,val);
void updateRange(int node, int start, int end, int l, int r, ll val)
{
    if(lazy[node] != 0){ 
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

// queryRange(1,1,n,l,r)
ll queryRange(int node, int start, int end, int l, int r){
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif

	for(int i=0;i<)
		
	return 0;	
}

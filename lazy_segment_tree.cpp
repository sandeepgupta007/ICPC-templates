// sandeep_007  
 
#include <bits/stdc++.h>
 
using namespace std; 
 
#define PI acos(-1)
#define mod 1000000007
#define ll long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define vi vector < ll >
#define mod 1000000007

bool sortbysec(const pair<ll,ll> &A,
              const pair<ll,ll> &b){
    return (A.second < b.second);
}
 
inline ll mx(ll A,ll b){
    if(A > b) return A;
    else return b;      
}

ll power(ll x,ll y,ll p){
    ll res = 1;   
    x = x % p;    
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; 
        x = (x*x) % p; 
    }
    return res;
}

ll gcd(ll A,ll b){if(b==0) return A; else return gcd(b,A%b);}

ll A[1000005];
ll seg_tree[5000001];
ll lazy[5000001]={0};

void build(int start, int end, int nod_num){
    if(start == end){
        seg_tree[nod_num] = A[start];
        return;
    }
    int mid = (start+end)/2;
    build(start,mid,2*nod_num+1);
    build(mid+1,end,2*nod_num+2);
    seg_tree[nod_num] = min(seg_tree[2*nod_num+1],seg_tree[2*nod_num+2]);
    return;
}

void update(int node, int start, int end,int val,int l,int r){
    if(lazy[node] != 0){
        seg_tree[node] += lazy[node];
        if(start != end){
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(l > end or r < start)
        return;
    if(l <= start and r >= end){
        seg_tree[node] += val;
        if(start != end){
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2+1,start,mid,val,l,r);
    update(node*2+2,mid+1,end,val,l,r);
    seg_tree[node] = min(seg_tree[2*node+1],seg_tree[2*node+2]);
    return;
}

ll query(int node,int start,int end, int l, int r){
    if(l > end or r < start){
        return INT_MAX;
    }
    if(lazy[node] != 0){
        seg_tree[node] += lazy[node];
        if(start != end){
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l <= start and r >= end){
        return seg_tree[node];
    }
    int mid = (start+end)/2;
    ll p1 = query(node*2+1,start,mid,l,r);
    ll p2 = query(node*2+2,mid+1,end,l,r);
    return min(p1,p2);
}



int main () {
    nitro;
    #ifdef DBG
        freopen("in","r",stdin);
    #endif
    
    int n,q; cin >> n >> q; // int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int j=0;j<4*n;j++) seg_tree[j]=INT_MAX;
    build(0,n-1,0);
    for(int i=0;i<q;i++){
        string s; cin >> s;
        int l,r,val; 
        if(s == "q"){
            cin >> l >> r;
            l--;r--;
            cout << query(0,0,n-1,l,r) << "\n";
        }
        else{
            cin >> l >> r >> val;
            l--;r--;
            update(0,0,n-1,val,l,r);
        }
        // cout << "seg_tree -> "; 
        // for(int j=0;j<4*n;j++) cout << seg_tree[j] << " ";
        // cout << "\n";
        // cout << "lazy ->     ";
        // for(int j=0;j<4*n;j++) cout << lazy[j] << " ";
        // cout << "\n"; 
    }
    // for(int i=0;i<4*n;i++) cout << seg_tree[i] << " ";
    // cout << "\n";
    // cout << seg_tree[0] << "\n";
    return 0 ;
}

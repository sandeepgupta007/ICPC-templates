// Sandeep Gupta
// IIIT Jabalpur
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair

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

ll max(ll a,ll b){
    if(a > b) return a;
    return b;
}

struct co{
    ll sx,sy,fx,fy,index;
};

bool cmp(co a, co b){
    if(a.sx != b.sx)
        return a.sx < b.sx;
    
    return a.fx < b.fx;
}

ll tree[4000000];

void build(int s,int e,int nod_num,ll A[]){
	if(s == e){
		tree[nod_num] = A[s];
		return;	
	}
	int m = (s+e)/2;
	
	build(s,m,nod_num*2,A);
	build(m+1,e,nod_num*2+1,A);
	
	tree[nod_num] = max(tree[2*nod_num],tree[2*nod_num+1]);
	return;	
}

ll query(int l,int r,int s,int e,int nod_num){
	if(s > r or e < l)	return -10000000000;
	else if(s >= l and e <= r) return tree[nod_num];
	else{
		int m = (s+e)/2;
		return max(query(l,r,s,m,2*nod_num),query(l,r,m+1,e,2*nod_num+1));
	}
}

int main(){
	nitro;

    //for(int i=0;i<=4*n;i++) tree[i] = 0;
    //build(1,n,1,A);
	return 0;
} 

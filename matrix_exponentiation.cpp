// sandeep_007  
#include <bits/stdc++.h>
 
using namespace std; 
 
#define PI acos(-1)
// #define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define vi vector < int >
#define mod 1000000000
#define md 998244353
#define rep(i,a,b) for(int i=a;i<b;i++)
#define FF first
#define SS second
#define all(a) (a).begin(),(a).end()

vector<vector<ll> > multiply(vector<vector<ll> > x,vector<vector<ll> > res,ll k) {
	vector<vector<ll> > vec(k+1,vector<ll>(k+1,0));
	rep(i,1,k+1){
		rep(j,1,k+1){
			rep(l,1,k+1){
				vec[i][j] += ((x[i][l]%mod)*(res[l][j]%mod))%mod;
				vec[i][j] = vec[i][j]%mod;
			}
		}
	}
	return vec;
}

ll solve(vector<ll> b,vector<ll> c,ll n,ll k){
	vector<vector<ll> > res(k+1,vector<ll>(k+1)); 
	rep(i,0,k+1) rep(j,0,k+1) if(i == j) res[i][j] = 1; else res[i][j] = 0;
	vector<vector<ll> > x(k+1,vector<ll>(k+1,0));
	rep(i,0,k+1) rep(j,0,k+1) {
		if(i == 1) x[i][j] = c[j];
		else if(i-1 == j) x[i][j] = 1;
	}
	while(n > 0){
		if(n&1){
			res = multiply(x,res,k);
		}
		x = multiply(x,x,k);
		n = n>>1;
	}
	ll ans = 0;
	rep(i,1,k+1) { 
		ans += ((res[1][i]%mod)*(b[k-i+1]%mod))%mod;
		ans = ans%mod;
	}
	return ans;			
}

int main () {
    nitro;
 
    #ifdef DBG
        freopen("in","r",stdin);
    #endif
    
    int t; cin >> t;
    while(t--){
    	ll k; cin >> k;
    	vector<ll> b(k+1); rep(i,1,k+1) cin >> b[i];
    	vector<ll> c(k+1); rep(i,1,k+1) cin >> c[i];
    	ll n; cin >> n; 
    	if(n <= k) cout << b[n] << endl;
    	else{
			n-=k;
			// cout << n << endl;
			cout << solve(b,c,n,k) << endl;
		}
    }
    return 0;
}   

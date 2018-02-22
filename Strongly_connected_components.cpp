// sandeep_007	
// strongly connected components

#include <bits/stdc++.h>
 
using namespace std;
 
#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define INV 333333336
#define arr(a,n) for(ll i=0;i<n;i++) cin >> a[i];
#define all(v) (v).begin(),(v).end()
#define br cout<<endl

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return (a.second < b.second);
}

ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}

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

vector < int > adj[100005];
vector < int > rev[100005];
bool vis[100005];
vector < int > vec;

void dfs(int u){
	vis[u] = true;
	for(auto v:adj[u]){
		if(!vis[v]){
			dfs(v);		
		}
	}
	vec.pb(u);	
}

void rdfs(int u){
	vis[u] = true;
	for(auto v:rev[u]){
		if(!vis[v])
			rdfs(v);	
	}
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	int n,m; cin >> n >> m;
	int a,b;	
	for(int i=0;i<m;i++){
		cin >> a >> b;
		adj[a].pb(b);
		rev[b].pb(a);
	}	

	for(int i=0;i<=n;i++) vis[i] = false;
	//vector < int > vec; 

	for(int i=1;i<=n;i++) if(!vis[i])  dfs(i);	
	//cout << vec.size(); br;
	//for(auto v:vec) cout << v << " ";br;

	for(int i=0;i<=n;i++) vis[i] = false;
	
	int ans=0;
	for(int i=vec.size()-1;i>=0;i--){
		if(!vis[vec[i]]){
			ans++;
			rdfs(vec[i]);			
		}	
	}
	cout << ans;br;
	
	return 0;	
}

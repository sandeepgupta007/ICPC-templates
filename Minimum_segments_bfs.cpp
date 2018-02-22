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
bool vis[100005];

int bfs(int u,int y,int n){
	queue < int > q;
	int dist[n+1];
	for(int i=1;i<=n;i++) dist[i]=INT_MAX;
	q.push(u);
	vis[u]=true;
	dist[u]=0;
	while(!q.empty()){
		int a = q.front();
		q.pop();
		vis[a]=true;
		for(auto v:adj[a]){
			dist[v] = min(dist[v],dist[a]+1);
			if(!vis[v]){
				q.push(v);	
			}
		}		
	}
	if(dist[y] == INT_MAX)
		return 	-1;
	else return dist[y];
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
		adj[b].pb(a);
	}	
	for(int i=0;i<=n;i++) vis[i]=false;
	int u,v; cin >> u >> v;	
	cout << bfs(u,v,n); br;	
	return 0;	
}

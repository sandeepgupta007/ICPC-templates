// sandeep_007	
// dijstra's algorithm

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

void shortest(int n,vector < pair<int,int> > adj[],vector<int> &dist,int src){
	set < pair <int,int> > sp;	
	sp.insert(make_pair(0,src));
	dist[src] = 0;
	while(!sp.empty()){
		pair <int,int> temp = *(sp.begin());
		sp.erase(sp.begin());
		int u = temp.second;
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if(dist[v] > dist[u]+w){
				if(dist[v] != INT_MAX){
					sp.erase(sp.find(make_pair(dist[v],v)));			
				}
				dist[v] = dist[u]+w;
				sp.insert(make_pair(dist[v],v));				
			}			
		}
	}	
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	int n,m; cin >> n >> m;
	vector < pair<int,int> > adj[n+1];
	vector < int > dist(n+1);
	int a,b,c;	

	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		adj[a].pb(mp(b,c));
		//adj[b].pb(mp(a,c));
	}	

	for(int i=1;i<=n;i++) dist[i]=INT_MAX;

	int u,v; cin >> u >> v;
	shortest(n,adj,dist,u);

	if(dist[v] == INT_MAX) cout << -1 <<endl;
	else cout << dist[v] << endl;
	
	return 0;	
}

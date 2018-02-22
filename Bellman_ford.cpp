// sandeep_007	

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

bool vis[100005];
vector < string > s;

// shortest path when path is neg and there is a possibility of neg cycles

/*
	output:
	if path exist - path length
	if neg cycle - '-'
	if path doesn't exist - '-'

*/

vector < pair < int,ll > > graph[100005];

int bellman_ford(int src,int n,vector<pair<int, pair <int,ll> > > adj){	
	vector < ll > dist(n+1);
	vector < int > pre(n+1);		

	for(int i=0;i<=n;i++) dist[i]=1e15;

	dist[src] = 0;
	pre[src] = src;
	vis[src] = true;

	for(int i=0;i<n-1;i++){
		for(int j=0;j<adj.size();j++){
			int u = adj[j].first;
			int v = adj[j].second.first;
			ll w = adj[j].second.second;
			if(dist[u] != 1e15 and dist[v] > dist[u]+w){
				vis[v] = true;				
				dist[v] = dist[u]+w;
				pre[v] = u;
			}
		}		
	}
	
	string a = " ";
	for(int i=0;i<=n;i++) s.pb(a);
	set < int > st;
	for(int j=0;j<adj.size();j++){
		int u = adj[j].first;
		int v = adj[j].second.first;
		ll w = adj[j].second.second;
		if(dist[u] != 1e15 and dist[v] > dist[u]+w){
			st.insert(v);		
		}
	}
	
	// bfs
	int vi[n+1]={0};
	for(auto it:st){
		queue < int > q;
		q.push(it);
		while(!q.empty()){
			int a = q.front();
			q.pop();
			vi[a] = 1;
			for(auto v:graph[a]){
				if(!vi[v.first]) q.push(v.first);	
			}	
		}	
	}
	
	for(int j=1;j<=n;j++){
		if(vi[j] != 1){
			if(dist[j] == 1e15) s[j] = "*";
			else s[j] = to_string(dist[j]);
		}
		else s[j] = "-";
	}
	return 0;
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	int n,m; cin >> n >> m;
	vector < pair<int,pair<int,ll> > > adj;
	ll a,b,c;	
	
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		adj.pb(mp(a,mp(b,c)));
		graph[a].pb(mp(b,c));
	}	
	
	for(int i=1;i<=n;i++) vis[i] = false;	
	int u; cin >> u;
	
	bellman_ford(u,n,adj);
	
	for(int i=1;i<=n;i++) cout << s[i] << endl;
	return 0;	
}

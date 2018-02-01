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
#define br cout << "\n"
#define rep(i,a,b) for(int i=a;i<b;i++)


bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b){
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

bool vis[500005],rec[500005];
vector < int > adj[500005];

bool iscycle(int v){
    /* to be inserted in the code
        for(int i=0;i<=n;i++){
            vis[i] = rec[i] = false;
        }
    */    
    if(vis[v] == false){
        vis[v] = true;
        rec[v] = true;
        for(auto i:adj[v]){
            if(!vis[i] && iscycle(i))
                return true;
            else if(rec[i])
                return true;
        }
    }
    rec[v] = false;
    return false;
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
    int n,m; cin >> n >> m;
    string s; cin >> s;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
    }
   
    for(int i=0;i<=n;i++)
        vis[i] = rec[i] = false;
    
    for(int i=1;i<=n;i++){
        bool temp = iscycle(i);
        if(temp == true){
            cout << -1; br;
            return 0;
        }
        if(!vis[i]){
            dfs(i); 
        }
    }
    cout << ans; br;
	return 0;	
}

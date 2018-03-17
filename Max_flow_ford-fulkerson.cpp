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
#define arr(a,n) for(int i=0;i<n;i++) cin >> a[i];
#define all(v) (v).begin(),(v).end()
#define br cout<<endl

int adj[200][200];
int parent[200];

void init(){
    for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
            adj[i][j] = 0;
}

int bfs(int src,int en,int V){
    queue < int > q;
    int vis[200+1]={0};
    q.push(src);
    vis[src] = 1;
    parent[src]=-1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=1;i<=V;i++){
            if(vis[i] == 0 and adj[u][i] > 0){
                q.push(i);
                vis[i]=1;
                parent[i] = u;
            }
        }
    }
    if(vis[en] == 1) return 1;
    return 0;
}

ll maxflow(int src,int en,int V){
    ll ans = 0;
    while(bfs(src,en,V) == 1){
        int path_flow = INT_MAX;
        for(int i=en;i!=src;i=parent[i]){
            int u = parent[i];
            path_flow = min(path_flow,adj[u][i]);
        }
        for(int i=en;i!=src;i=parent[i]){
            int u = parent[i];
            adj[u][i] -= path_flow;
            adj[i][u] += path_flow;
        }
        //cout << path_flow << " ";
        ans += path_flow;
    }
    return ans;
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	// Code begins from here
	
    init();
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a][b] += c;
    }
    
	cout << maxflow(1,n,n) << endl;
	
		
	return 0;	
}

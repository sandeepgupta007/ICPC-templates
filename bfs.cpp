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

vector < int > adj[1000000];

pair<int,int> bfs(int src,int n){
	queue < int > q;
	q.push(src);
	int dis[n+1];
	memset(dis,-1,sizeof(dis));
	dis[src] = 0;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int i=0;i<adj[t].size();i++){
			int v = adj[t][i];
			if(dis[v] == -1){
				q.push(v);
				dis[v] = dis[t]+1;		
			}		
		}	
	}
	int m = 0;
	int mi;
	for(int i=1;i<=n;i++){	
		if(dis[i] > m){
			m = dis[i];
			mi = i;
		}	
	}
	return mp(mi,m);
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	return 0;	
}

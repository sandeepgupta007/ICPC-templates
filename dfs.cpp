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

int dfs(int src){
	vis[src] = 1;
	for(int i=0;i<adj[src].size();i++){
		if(vis[adj[src][i]] == 0)
			dfs(adj[src][i]);		
	}
	return 0;
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	return 0;	
}

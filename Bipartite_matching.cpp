// sandeep_007	
// Yet to be done.

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
int n,m;

int dfs(int u,bool seen[],vector < int > &match){
	for(int i=0;i<m;i++){
		if(adj[u][i] > 0 and !seen[i]){
			seen[i] = 1;
			if(match[i] < 0 or dfs(match[i],seen,match)){
				match[i] = u;
				return 1;
			}		
		}	
	}
	return 0;
}

vector< int > bipartite_matching(){
	vector < int > match(200,-1);
	//memset(match,-1,sizeof(match));
	for(int i=0;i<n;i++){
		bool seen[201];
		memset(seen,0,sizeof(seen));
		dfs(i,seen,match);	
	}
	return match;
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif

	// Code begins from here
	cin >> n >> m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> adj[i][j];
	vector < int > ans;
	ans = bipartite_matching();
	int A[200+1];
	memset(A,-1,sizeof(A));
	for(int i=0;i<n;i++){
		if(ans[i] >= 0)
			A[ans[i]] = i;	
	}	
		
	for(int i=0;i<n;i++){
		if(A[i] < 0) cout << A[i] << " ";
		else cout << A[i]+1 << " ";
	}
	cout << endl;
	return 0;	
}

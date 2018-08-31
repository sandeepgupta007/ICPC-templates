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
#define mod 1000000007

bool sortbysec(const pair<int,int> &A,
              const pair<int,int> &b){
    return (A.second < b.second);
}
 
inline int mx(int A,int b){
    if(A > b) return A;
    else return b;      
}

int power(int x,int y,int p){
    int res = 1;   
    x = x % p;    
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; 
        x = (x*x) % p; 
    }
    return res;
}

int gcd(int A,int b){if(b==0) return A; else return gcd(b,A%b);}

// mulutisource bfs
void mulutisourceBFS(int n,vector < pair<int,int> > adj[],vector < int >&dist,vector < int > src){
    set < pair<int,int> > sp;
    for(int i=0;i<src.size();i++){
        sp.insert(mp(0,src[i]));
        dist[src[i]] = 0;
    }
    while(!sp.empty()){
        pair<int,int> temp = *(sp.begin());
        sp.erase(sp.begin());
        int u = temp.second;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[v] > dist[u]+w){
                if(dist[v] != INT_MAX){
                    sp.erase(sp.find(mp(dist[v],v)));
                }
                dist[v] = dist[u]+w;
                sp.insert(mp(dist[v],v));
            }
        }
    }
}

int main () {
    nitro;
    #ifdef DBG
        freopen("in","r",stdin);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        string s[n+1];
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        int vCount = 1;
        vector < pair<int,int> > adj[n*m+1]; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vCount%m != 0){
                    adj[vCount].pb(mp(vCount+1,1));
                    adj[vCount+1].pb(mp(vCount,1));
                    // cout << "(" << vCount << " " << vCount+1 << ") ";
                }
                if(vCount+m <= n*m){
                    adj[vCount+m].pb(mp(vCount,1));
                    adj[vCount].pb(mp(vCount+m,1));
                    // cout << "(" << vCount << " " << vCount+m << ") ";
                }
                vCount++;    
            }
        }

        // cout << vCount << "\n";
        vector < int > sources;
        int count = 1;
        vector < int > dist(n*m+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i][j] == '1'){
                    sources.pb(count);
                    dist[count] = 0; // Step Repeated
                }
                else{
                    dist[count] = INT_MAX;
                }
                count++;
            }
        }
        mulutisourceBFS(n,adj,dist,sources);
        count = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dist[count] << " ";
                count++;
            }
            cout << "\n";
        }
        // cout << "\n";
    }
    return 0;
}

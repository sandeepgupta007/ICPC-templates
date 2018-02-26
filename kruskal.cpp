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

double d(int x,int y,int x1,int y1){
	double ans = (x-x1)*(x-x1)+(y-y1)*(y-y1);
	return sqrt(ans);
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	int n; cin >> n;
	vector < pair <int,int> > vec;
	for (int i = 0; i < n; i += 1){
		int a,b; cin >> a >> b;
		vec.pb({a,b});
	}
	vector < pair<double,pair<int,int> > > dist;
	
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j += 1){			
			if(i!=j)
			dist.pb({d(vec[i].first,vec[i].second,vec[j].first,vec[j].second),{i,j}});
		}
	}
	
	sort(dist.begin(),dist.end());

	vector < set< int > > parent(n+1);
	for (int i = 0; i < n; i += 1){ set< int > s; s.insert(i); parent[i] = s; }
	
	int count = 0;
	double	ans = 0;	
	for (int i = 0; i < dist.size(); i += 1){
		if(count >= n) break;
		else{
			int a = dist[i].second.first;
			int b = dist[i].second.second;
			int index1=-1,index2=-2;
			for (int j = 0; j < n; j += 1){
				if(parent[j].find(a) != parent[j].end()) index1 = j;	
				if(parent[j].find(b) != parent[j].end()) index2 = j;
				if(index1 != -1 and index2 != -2) break;
			}					
			if(index1 != index2){
				count++;	
				if(parent[index1].size() < parent[index2].size()){
					for(auto v:parent[index1])
						parent[index2].insert(v);
					parent[index1].clear();	
				}
				else{
					for(auto v:parent[index2])
						parent[index1].insert(v);
					parent[index2].clear();	
				}
				ans = ans + dist[i].first;					
			}
		}
	}
	cout << fixed;
	cout << setprecision(10) << ans;br;
	
		
		
	
	return 0;	
}

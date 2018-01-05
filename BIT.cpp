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

bool sortbysec(const pair<ll,ll> &a,
              const pair<ll,ll> &b){
    return (a.second < b.second);
}

ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}

ll power(ll x,ll y){
    ll res = 1;       
    while (y > 0){
        if (y & 1)
            res = (res*x);
 
        y = y>>1; 
        x = (x*x); 
    }
    return res;
}


vector < ll > bit(vector < ll > a){
	int n = a.size()+1;		
	vector < ll > b(n);

	for(int i=0;i<n;i++) b[i] = 0;
	
	for(int i=0;i<a.size();i++){
		int index = i+1;
		while(index < n){
			b[index] += a[i];
			index += (index&(-index));
		}
	}
	return b;
}

ll bitsum(vector < ll > a,int index){
	ll sum = 0;
	while(index > 0){
		sum += a[index];
		index -= (index&(-index));
	}
	return sum;
}

vector < ll > bitupdate(vector < ll > a,int index,ll val){
	ll pre = val-a[index];	
	while(index <= a.size()){
		a[index] += pre;
		index += (index&(-index));
	}
	return a;
} 

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	int n = 5;
	vector < ll > a(5);
	for(int i=0;i<n;i++) a[i] = i+1;
	
	vector < ll > b(5);
	b = bit(a);
	vector < ll > c(5);
	c = bitupdate(b,3,100);
	b.clear();
	b = c;
	c.clear();
	for(int i=1;i<=5;i++){
		cout << bitsum(b,i) << " ";	
	}
	
	return 0;
}

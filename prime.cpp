// sandeep_007	
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define PI acos(-1)
#define mod 1000000000
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

ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}

// pri[i] == 1 for prime and 
// pri[i] == 0 for non-prime

ll pri[10000000];

int prime(ll n){
	for(ll i=0;i<=n;i++)
		pri[i] = 1;	
	pri[0] = 0;
	pri[1] = 0;
	for(ll i=2;i<=sqrt(n+1)+1;i++){
		if(pri[i] == 1){
			//pri[i] = 0;
			for(ll j=2*i;j<=n;j+=i){
				pri[j] = 0;
			}
		}	
	}		
	return 0;
}

int main(){
	nitro;
	//prime(10000000);
	
	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
	prime(10000);
	for(int i=0;i<300;i++){
		if(pri[i] == 1) cout << i << " ";	
	}
 	return 0;	
}

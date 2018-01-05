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

vector < pair<ll,ll> > factors(ll a){
	vector < pair<ll,ll> > ans;
	ll c = 0;
	if(a%2 == 0){
		while(a%2 == 0){
			a=a/2;
			c++;
		}
		ans.pb(mp(2,c));
	}
	
	for(ll i=3;i<=sqrt(a);i+=2){
		if(a%i == 0){
			c=0;
			while(a%i == 0){
				c+=1;				
				a = a/i;
			}
			ans.pb(mp(i,c));
		}	
	}

	if(a > 2)
		ans.pb(mp(a,1));
	return ans;
}

int main(){
	nitro;
	//prime(10000000);
	
	#ifdef DBG
		freopen("in","r",stdin);
	#endif
	
 	return 0;	
}

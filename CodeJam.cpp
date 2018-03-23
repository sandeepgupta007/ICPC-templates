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

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif

	// Code begins from here
	int n,k; cin >> n >> k;
	int A[n+1][k+1];
	for(int i=0;i<n;i++) for(int j=0;j<k;j++) cin >> A[i][j];
	set < int > s[n+1];
	int count = 0;
	s[0].insert(0);
	count++;
	for(int i=1;i<n;i++){
		int j=0;
		int f = 0;		
		while(j < count){
			set <int>::iterator it;
			it=s[j].begin();
			f=0;						
			while(it!=s[j].end()){
				int index = *it;				
				for(int l=0;l<k;l++){
					if(A[i][l] <= A[index][l]){
						f=1;
						break;
					}
				}
				it++;
				if(f == 1) break;
			}
			if(f == 0){
				s[j].insert(i);
				break;
			}
			j++;
		}
		if(f == 1){
			s[j].insert(i);
			count++;
		}
	}
	cout << count << endl;
	return 0;	
}

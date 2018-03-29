// sandeep_007	
// To be completed

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

double A[100+1][100+2];
int n;
	
int swapRow(int index1,int index2){
	for(int i=0;i<n;i++)
		swap(A[index1][i],A[index2][i]);
}

int main(){
	nitro;

	#ifdef DBG
		freopen("in","r",stdin);
	#endif

	// Code begins from here
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			cin >> A[i][j];	
		}
	}
	
	for(int i=0;i<n;i++){
		int row = i;
		int val = A[i][i];
		for(int j=i+1;j<n;j++){
			if(abs(A[j][i]) > val){
				val = A[j][i];
				row = j;	
			}
		}
		if(A[i][row] == 0)
			return 0;	
		if(i != row){
			swapRow(i,row);	
		}
		for(int j=i+1;j<n;j++){
			double f = A[j][i]/A[i][i];
			for(int k=i+1;k<=N;k++)
				A[j][k] -= A[i][k]*f;
			A[j][i] = 0;
		}		
	}	
	return -1;	
}

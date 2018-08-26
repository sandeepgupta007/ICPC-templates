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


/** longest proper prefix which is also a suffix
    used in KMP Substring search algorithm
*/
vector < int > lps(string s){
    vector < int > vec(s.length(),0);
    int pre = 0;
    int i = 1;
    while(i < s.length()){
        if(s[i] == s[pre]){
            pre++;
            vec[i] = pre;
            i++;
        }
        else{
            if(pre != 0){
                pre = vec[pre-1];
            }
            else{
                vec[i] = 0;
                i++;
            }
        }
    }
    return vec; 
} 

vector < int > KMP(string s,string a,vector < int > lpsa){
    int i=0,j=0;
    int countA = 0;
    vector < int > ans(s.length(),0);
    while(i < s.length()){
        if(a[j] == s[i]){
            i++;
            j++;
        }
        if(j == a.length()){
                ans[i-j] = 1;    
            j = lpsa[j-1];
        }
        else if(i < s.length() and a[j] != s[i]){
            if(j != 0){
                j = lpsa[j-1];
            }
            else{
                i++;
            }
        }
    }
    return ans;
}

int main () {
    nitro;
    #ifdef DBG
        freopen("in","r",stdin);
    #endif
        
    int t; cin >> t;
    while(t--){
        string a,b; cin >> a >> b;
        vector < int > vec = lps(b);
        vector < int > pos = KMP(a,b,vec);
        vector < int > ans;
        for(int i=0;i<pos.size();i++){
            if(pos[i] == 1) ans.pb(i+1);
        }
        if(ans.size() == 0){
            cout << "Not Found\n";
        }
        else{
            cout << ans.size() << "\n";
            for(int i=0;i<ans.size();i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}

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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b){
    return (a.second < b.second);
}
 
inline ll mx(ll a,ll b){
    if(a > b) return a;
    else return b;      
}

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

ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b);}
// global variables declaration   

// Trie implementation
struct Trie{
    Trie* children[27];
    bool isEndOfWord;
};

// Getting a node, for each element.
Trie* getNode(){
    Trie* node = new Trie;
    node->isEndOfWord = false;
    for(int i=0;i<27;i++){
        node->children[i] = NULL;
    }
    return node;
}

// inserting in a Trie
void insertTrie(Trie *root,string key){
    struct Trie *node = root;
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        if(!node->children[index]){
            node->children[index] = getNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// Searching in a Trie
string searchTrie(Trie* root, string key){
    struct Trie* node = root;
    string ans = "";
    for(int i=0;i<key.length();i++){
        int index = key[i]-'a';
        if(!node->children[index]){
            break;
        }
        node = node->children[index];
        ans += key[i];
    }
    return ans;
}


// begin main function.
int main(){
    nitro;

    #ifdef DBG
        freopen("in","r",stdin);
    #endif
    
    Trie *root = getNode();

    insertTrie(root,"sandeep");
    insertTrie(root,"gupta");
    insertTrie(root,"coviam");
    cout << searchTrie(root,"sand") << "\n";
    cout << searchTrie(root,"fjgf") << "\n";
    cout << searchTrie(root,"sandeep1") << "\n";

    
    
    return 0;
}

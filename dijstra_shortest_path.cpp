// Reverse Linked list

#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define br cout << "\n"
#define pb push_back

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

// dijstra's algorithm O(Elog(V))
void shortest(int n,vector < pair<int,int> > adj[],vector<int> &dist,int src){
	set < pair <int,int> > sp;	

	sp.insert(make_pair(0,src));
	dist[src] = 0;
	while(!sp.empty()){
		pair <int,int> temp = *(sp.begin());
		sp.erase(sp.begin());
	
		int u = temp.second;
		
		for(int i=0;i<adj[u].size();i++){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			
			if(dist[v] > dist[u]+w){
				if(dist[v] != INT_MAX){
					sp.erase(sp.find(make_pair(dist[v],v)));			
				}
				dist[v] = dist[u]+w;
				sp.insert(make_pair(dist[v],v));				
			}			
		}
	}	
}

struct nodes{
	int val;
	nodes *next;
};

nodes* newNode(int key){
	nodes* temp;
	temp = (nodes *)malloc(sizeof(nodes));
	temp->val = key;
	temp->next = NULL;
	return temp;
}

nodes* insert(nodes *A,int key){
	if(A == NULL){
		return newNode(key);	
	}
	A->next = insert(A->next,key);
}

nodes* reverse(nodes *A){
	nodes *curr=A, *pre=NULL,*temp;

	while(curr != NULL){
		temp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = temp;
	}
	return pre;	
}

void print(nodes* A){
	while(A != NULL){
		cout << A->val << " ";
		A = A->next;
	}
	cout << "\n";
}

int main(){
	//nitro;
	int n;
	cout << " Enter the number of nodes:\n";	
	cin >> n;
	int temp;
	nodes *head=NULL;
	for(int i=0;i<n;i++){
		cin >> temp;
		if(head == NULL)
			head = insert(head,temp);
		else
			insert(head,temp);	
	}
	print(head);
	head = reverse(head);
	print(head);
	return 0;
}







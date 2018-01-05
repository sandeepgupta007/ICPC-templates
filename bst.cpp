// Sandeep Gupta
// IIIT Jabalpur
 
#include <bits/stdc++.h>
#include <string>

using namespace std;
 
#define PI acos(-1)
#define mod 1000000007
#define ll long long
#define nitro std::ios_base::sync_with_stdio (false); cin.tie(NULL)
#define br cout << "\n"

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

struct bst{
	int data;
	struct bst* left, *right;
};

bst* newnode(int key){
	bst *temp;
	temp = (bst *)malloc(sizeof(bst));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;	
	return temp;
}

bst* insert(bst* head,int key){
	if(head == NULL){
		return newnode(key);
	}
	if(head->data > key){
		head->left = insert(head->left,key);
	}	
	else if(head->data < key){
		head->right = insert(head->right,key);
	}
	return head;
}

// finds the minimum value of given BST
bst* minval(bst *head){
	while(head->left != NULL){
		head = head->left;
	}
	return head;
}

bst *delbst(bst *head,int key){
	if(head == NULL)
		return head;
	
	if(head->data < key){
		head->left = delbst(head->left,key);	
	}
	else if(head->data > key){
		head->right = delbst(head->right,key);
	}
	else{
		if(head->left == NULL and head->right == NULL){
			return NULL;	
		}
		else if(head->left == NULL){
			return head->right;		
		}
		else if(head->right == NULL){
			return head->left;
		}
		else{
			bst *sr = minval(head);
			head->data = sr->data;
			head->right = delbst(head->right,sr->data);
		}
	}
	return head;
}

void inorder(bst *head,vector < int >& v){
	if(head == NULL) return;
	inorder(head->left,v);
	v.push_back(head->data);
	inorder(head->right,v);
}

int main(){
	//nitro;
	cout << "Enter number of elements in BST" << endl;
 	bst *head = NULL;	
	int n;	
	cin >> n;	
	int key;
	for(int i=0;i<n;i++){	
		cin >> key;
		if(head == NULL){
			head = insert(head,key);			
		}
		else{
			insert(head,key);
		}
	}
	
	vector < int > v;
	inorder(head,v);
	
	for(int i=0;i<v.size();i++) cout << v[i] << " ";
	v.clear();
	
	while(n--){
		cin >> key;
		delbst(head,key);
		inorder(head,v);	
		for(int i=0;i<v.size();i++) cout << v[i] << " ";
		v.clear();
	
	}
	
	//cout << "Inorder Traversal: "; inorder(head); br;
	
	
		
	

	return 0;
} 

struct trie{
    trie *a[2];
    bool isEndOfWord;
};

trie *getNode(){
    trie *node = new trie;
    node->isEndOfWord = false;
    node->a[0] = NULL;
    node->a[1] = NULL;
    return node;
}

void insert(trie *root, string s){
    trie *node = root;
    for(int i=0;i<s.length();i++){
        int index = s[i]-'0';
        if(node->a[index] == NULL)
            node->a[index] = getNode();
        node = node->a[index];
    }
    root->isEndOfWord = true;
}

string search(trie* root,string s){
    trie *node = root;
    string ans = "";
    // cout << "search" << " "; 
    for(int i=0;i<s.length();i++){
        int index = s[i]-'0';
        // cout << index;
        if(node->a[1-index] != NULL){
            ans = ans + '1';
            node = node->a[1-index];
        }
        else{
            ans = ans + '0';
            node = node->a[index];
        }
    }
    // cout << endl;
    return ans;
}

// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> queries) {
    // solve here
    trie *root = getNode();
    for(int i=0;i<arr.size();i++){
        string s = "";
        int num = arr[i];
        // cout << arr[i] << " ";
        for(int i=0;i<32;i++){
            if((num&(1<<i)))
                s = '1'+s;
            else
                s = '0'+s;
        }
        // cout <<s << endl;
        insert(root,s);
    }
    vector<int> ret;
    for(int i=0;i<queries.size();i++){
        int num = queries[i];
        string s = "";
        for (int i = 0; i < 32; i++) {
          if ((num & (1 << i)))
            s = '1' + s;
          else
            s = '0' + s;
        }
        cout << s << endl;
        string ans = search(root,s);
        cout << ans << endl;
        int num1 = 0;
        int j = 0;
        for(int i=31;i>=0;i--){
            if(ans[i] == '1')
                num1 += (1<<j);
            j++;
        }
        ret.push_back(num1);
    }
    return ret;
}

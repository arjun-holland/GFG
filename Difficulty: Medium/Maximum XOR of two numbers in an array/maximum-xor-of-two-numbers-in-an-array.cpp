//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct TrieNode {   // Trie Node
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Solution {
  public:
    void insert(TrieNode* root,int num){
        TrieNode* cur = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(!cur->child[bit]){
                cur->child[bit] = new TrieNode();
            }
            cur = cur->child[bit];
        }
    }
    int findMaxXor(TrieNode* root,int num){
        TrieNode* cur = root;
        int res = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            int opposite_bit = 1 - bit;
            if(cur->child[opposite_bit]){
                res = res | (1 << i);
                cur = cur->child[opposite_bit];
            }
            else cur = cur->child[bit];
        }
        return res;
    }
    int maxXor(vector<int> &arr) {
        TrieNode* root = new TrieNode();
        insert(root,arr[0]);
        int maxXor = 0;
        for(int i=1;i<arr.size();i++){
            maxXor = max(maxXor,findMaxXor(root,arr[i]));
            insert(root,arr[i]);
        }
        return maxXor;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(int i,vector<int>& ans,unordered_map<int,vector<int>>& mp,vector<bool>& v){
        if(v[i] == true)return;
        v[i] = true;
        ans.push_back(i);
        for(int j=0 ; j< mp[i].size(); j++){
            solve(mp[i][j],ans,mp,v);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        unordered_map<int,vector<int>> mp;
        for(int i=0 ;i<adj.size(); i++){
            mp[i] = adj[i];
        }
        vector<bool> visited(adj.size(),false);
        vector<int> ans;
        solve(0,ans,mp,visited);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
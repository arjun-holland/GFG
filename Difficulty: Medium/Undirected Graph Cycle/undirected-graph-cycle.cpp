//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool checker(vector<bool>& visited, unordered_map<int, vector<int>>& mp, int u) {
        queue<pair<int, int>> q;
        q.push({-1, u});
        visited[u] = true;
        while (!q.empty()) {
            int parent = q.front().first;
            int node = q.front().second;
            q.pop();  // Don't forget to pop!

            for (int neighbor : mp[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({node, neighbor});
                    } else if (neighbor != parent) {
                        // We've encountered a visited node that's not the parent — cycle!
                        return true;
                    }
                }
            }
            return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> mp;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(V,false);
        for(int i=0 ; i<V; i++){
            if(!visited[i]){
                if(checker(visited,mp,i))return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
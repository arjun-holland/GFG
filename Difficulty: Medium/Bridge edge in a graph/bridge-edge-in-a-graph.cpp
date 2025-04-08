//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int time = 0;
    bool foundBridge = false;
    
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, int c, int d) {
        disc[u] = low[u] = time++;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            
            if (disc[v] == -1) {
                dfs(v, u, adj, disc, low, c, d);
                
                low[u] = min(low[u], low[v]);
                
                // Check if this edge is a bridge
                if (low[v] > disc[u]) {
                    if ((u == c && v == d) || (u == d && v == c)) {
                        foundBridge = true;
                    }
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

public:
    bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
        vector<int> adj[V];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> disc(V, -1), low(V, -1);

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                dfs(i, -1, adj, disc, low, c, d);
            }
        }
        return foundBridge;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void DFS(int node, unordered_map<int, vector<int>>& adjL, vector<bool>& vis) {
        vis[node] = true;
        for (int ngh : adjL[node]) {
            if (!vis[ngh])
                DFS(ngh, adjL, vis);
        }
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        unordered_map<int, vector<int>> adjL;

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            if((u == c && v == d) || (u == d && v == c))continue;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        vector<bool> visited(V, false);
        DFS(c, adjL, visited);
        return !visited[d];
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
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>> adjL;
        vector<int> indegree(V,0);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adjL[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int vertix = q.front();
            q.pop();
            ans.push_back(vertix);
            for(int ngh : adjL[vertix]){
                indegree[ngh]--;
                if(indegree[ngh] == 0){
                    q.push(ngh);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
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
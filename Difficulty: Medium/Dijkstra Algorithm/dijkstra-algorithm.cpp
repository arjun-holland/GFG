//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto ed : edges){
            int u = ed[0];
            int v = ed[1];
            int w = ed[2];
            mp[u].push_back({v,w});
            mp[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min heap
        pq.push({0,src});
        vector<int> wt(V,1e5);
        wt[src] = 0;
        while(!pq.empty()){
            int w = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            for(auto ngh : mp[n]){
                int v = ngh.first;
                int vw = ngh.second;
                if(wt[v] > vw + w){
                    wt[v] = vw + w;
                    pq.push({wt[v], v});
                }
            }
        }
        return wt;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
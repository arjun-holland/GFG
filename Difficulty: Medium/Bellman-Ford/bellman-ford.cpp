//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> ans(V,1e8); //cost at V node
        ans[src] = 0;//cost of src is 0
        for(int i=0;i<V-1;i++){
            for(auto ed : edges){
                if(ans[ed[0]] == 1e8)continue;
                ans[ed[1]] = min(ans[ed[1]],ans[ed[0]]+ed[2]);
            }
        }
        for(auto ed : edges){
            if(ans[ed[0]] == 1e8)continue;
            if(ans[ed[1]] > ans[ed[0]]+ed[2]){
                return {-1};
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(unordered_map<int, vector<pair<int, int>>>& mp, int v) {//Primes - MST problem
        vector<bool> visited(v, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minH;

        minH.push({0, 0});  // {distance, node}
        int s = 0;
        while (!minH.empty()) {
            int dis = minH.top().first;
            int node = minH.top().second;
            minH.pop();
            if (visited[node]) continue;
            visited[node] = true;
            s += dis;

            for (auto& ngh : mp[node]) {
                if (!visited[ngh.first]) {
                    minH.push({ngh.second, ngh.first});
                }
            }
        }
        return s;
    }

    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int j=0;j<houses.size();j++){
            for(int i=j+1;i<houses.size();i++){
                int d = abs(houses[j][0]-houses[i][0]) + abs(houses[j][1]-houses[i][1]);
                mp[i].push_back({j,d});
                mp[j].push_back({i,d});
            }
        }
        return solve(mp,n);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends
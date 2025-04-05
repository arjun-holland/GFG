//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,+1},{+1,-1}};
    void landCheck(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& v){
        v[i][j] = true;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto d : directions){
                int r_ = r + d.first;
                int c_ = c + d.second;
                if(r_ >= 0 && r_ < grid.size() && c_ >= 0 && c_ < grid[0].size() && grid[r_][c_] == 'L' && v[r_][c_] == false){
                    v[r_][c_] = true;
                    q.push({r_,c_});
                }
            }
        }
    }
    
    int countIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'L' && visited[i][j] == false){
                    ans++;
                    landCheck(grid,i,j,visited);
                }
            }    
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
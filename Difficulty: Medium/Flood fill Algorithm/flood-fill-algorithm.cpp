//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(vector<vector<int>>& image,int sr,int sc,int n,int m,int oc,int nc){
        if(sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != oc ||  image[sr][sc] == nc)return;
        
        image[sr][sc] = nc;
        solve(image,sr+1,sc,n,m,oc,nc);
        solve(image,sr-1,sc,n,m,oc,nc);
        solve(image,sr,sc-1,n,m,oc,nc);
        solve(image,sr,sc+1,n,m,oc,nc);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size();//rows
        int m = image[0].size();//columns
        int oldColor = image[sr][sc];
        solve(image,sr,sc,n,m,oldColor,newColor);
        
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
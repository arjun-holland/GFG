//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &in,
                                       vector<int> &newIn) {
        vector<vector<int>> res;
        int i = 0;
        while(i<in.size() && newIn[0] > in[i][1]){
            res.push_back(in[i]);
            i++;
        }
        while(i<in.size() && in[i][0] <= newIn[1]){
            newIn[0] = min(in[i][0],newIn[0]);
            newIn[1] = max(in[i][1],newIn[1]);
            i++;
        }
        res.push_back(newIn);
        while(i < in.size()){
            res.push_back(in[i]);
            i++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
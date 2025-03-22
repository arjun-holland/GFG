//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Recurssion
// class Solution {
//   public:
//     int solve(vector<int>& arr,int i,int e){
//         if(i >= e)return 0;
        
//         int p = 0,np = 0;
//         p = arr[i] + solve(arr,i+2,e);
//         np = solve(arr,i+1,e);
        
//         return max(p,np);
//     }
//     int maxValue(vector<int>& arr) {
//         int n = arr.size();
//         return max(solve(arr,0,n-2),solve(arr,1,n-1));
//     }
// };

//DP
class Solution {
  public:
    int solve(vector<int>& arr, int i, int e, vector<int>& dp) {
        if (i > e) return 0; // Corrected condition (i > e instead of i >= e)
        
        if (dp[i] != -1) return dp[i];
        
        int p = arr[i] + solve(arr, i + 2, e, dp); // Pick current house
        int np = solve(arr, i + 1, e, dp); // Skip current house
        
        return dp[i] = max(p, np);
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0]; // Edge case: Single house

        vector<int> dp1(n, -1), dp2(n, -1); // Separate dp arrays
        return max(solve(arr, 0, n - 2, dp1), solve(arr, 1, n - 1, dp2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
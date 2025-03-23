//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string &s,int n,int i,vector<int>& dp){
        if(i == n)return 1;
        if(s[i] == '0')return 0;
        
        if(dp[i] != -1)return dp[i];
        int one = solve(s,n,i+1,dp);
        int two = 0;
        if(i != n-1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
            two = solve(s,n,i+2,dp);
        }
        return dp[i] = (one+two);
    }
    int countWays(string &digits) {
        int n = digits.size();
        vector<int> dp(n+1,-1);
        return solve(digits,n,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
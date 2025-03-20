//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int ind, int k, bool canbuy, const vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(k == 0 || ind >= prices.size())return 0;
        
        if(dp[ind][k][canbuy] != -1)return dp[ind][k][canbuy];
        
        int include = 0, ignore = 0;
        if(canbuy){ //for  buy
            include = -1*prices[ind] + solve(ind+1, k, false, prices, dp);
            ignore = solve(ind+1, k, true, prices, dp);
        }else{  // for sell
            include = prices[ind] + solve(ind+1, k-1, true, prices, dp);
            ignore = solve(ind+1, k, false, prices, dp);
        }
        return dp[ind][k][canbuy] =  max(include,ignore);
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2+1,vector<int>(2,-1)));
        return solve(0,2,true,prices,dp);
        
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
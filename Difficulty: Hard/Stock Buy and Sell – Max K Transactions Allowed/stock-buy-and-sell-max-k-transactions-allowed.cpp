//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//recursuion
// class Solution {
//   public:
//     int solve(int ind, int k, bool canbuy, const vector<int>& prices){
//         if(k == 0 || ind >= prices.size())return 0;
//         int include = 0, ignore = 0;
//         if(canbuy){
//             include = -1*prices[ind] + solve(ind+1, k, false, prices);
//             ignore = solve(ind+1, k, true, prices);
//         }else{
//             include = prices[ind] + solve(ind+1, k-1, true, prices);
//             ignore = solve(ind+1, k, false, prices);
//         }
//         return max(include,ignore);
//     }
    
//     int maxProfit(vector<int>& prices, int k) {
//         //int n = prices.size();
        
//         return solve(0,k,true,prices);
        
//     }
// };

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
    
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,k,true,prices,dp);
    }
};



//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
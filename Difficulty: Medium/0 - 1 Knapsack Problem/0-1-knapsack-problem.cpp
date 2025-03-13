//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1001][1001];//dp[i][j] : i - item , j - weight
    int solve(int w,vector<int> &val, vector<int> &wt,int i){
        if(i == wt.size())return 0;
        
        if(dp[i][w] != -1)return dp[i][w];
        int pick = 0,notpick = 0;
        if(w >= wt[i])
        pick = val[i]+solve(w-wt[i],val,wt,i+1);
        notpick = solve(w,val,wt,i+1);
        
        return dp[i][w] = max(pick,notpick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        memset(dp,-1,sizeof(dp));
        return solve(W,val,wt,0);
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
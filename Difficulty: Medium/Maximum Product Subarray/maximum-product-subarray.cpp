//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        // Initialize current maximum and minimum products
        int currMax = arr[0];
        int currMin = arr[0];
        int maxProd = arr[0];
    
        for (int i = 1; i < n; ++i) {
            if (arr[i] == 0) {// Reset when encountering zero
                currMax = 1;
                currMin = 1;
                continue;
            }
            // Store the current maximum before updating
            int temp = currMax;
            // Update currMax and currMin
            currMax = max(arr[i], max(arr[i] * currMax, arr[i] * currMin));
            currMin = min(arr[i], min(arr[i] * temp, arr[i] * currMin));
            // Update global maximum product
             maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
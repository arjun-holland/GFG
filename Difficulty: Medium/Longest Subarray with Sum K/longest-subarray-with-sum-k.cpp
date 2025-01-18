//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*Logic:

If the running sum (sum) equals k at any point,
it means the subarray from the start to the current index has the desired sum.
If the difference sum - k exists in the map,
it means there’s a prefix that can be excluded
to achieve the desired sum in the current subarray.
The length of such a subarray is calculated, 
and the maximum length is updated.*/
class Solution {
  public:
    int longestSubarray(vector<int>& a, int k) {
        // code here
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < a.size() ; i++) {
            sum += a[i];
        
        // Check if the current sum is equal to k
            if (sum == k) {
                maxLen = i + 1;
            }
        
        // If (sum - k) exists in the map, we have found a subarray
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                maxLen = max(maxLen, i - prefixSum[sum - k]);
            }
        
        // Add the current sum to the map if it's not already present
            if (prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }
        return maxLen;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
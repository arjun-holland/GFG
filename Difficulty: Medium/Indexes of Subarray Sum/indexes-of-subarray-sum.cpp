//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int i = 0, j = 0, n = arr.size();
        int s = 0;
        while (j < n) {
            s += arr[j]; // Add the current element to the sum
            
            // Shrink the window from the left as long as the sum exceeds the target
            while (s > target && i <= j) {
                s -= arr[i];
                i++;
            }
            
            // Check if the current sum equals the target
            if (s == target) {
                return {i + 1, j + 1};
            }
            
            // Move the right pointer
            j++;
        }
        
        // If no subarray is found, return -1
        return {-1};
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
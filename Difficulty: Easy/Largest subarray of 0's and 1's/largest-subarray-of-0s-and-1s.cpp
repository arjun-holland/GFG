//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int maxLen(vector<int> &arr) {
    // Replace all 0s in the array with -1s
    // This helps in transforming the problem into finding the longest subarray
    // with a sum of 0 (a common subarray problem).
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) 
            arr[i] = -1;
    }

    int k = 0; // Target sum (we are looking for subarrays with sum 0)
    int sum = 0; // Variable to store the running sum
    int length = 0; // Variable to store the maximum length of the subarray
    map<int, int> mp; // Hash map to store the first occurrence of a particular sum

    // Traverse the array
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // Add the current element to the running sum

        // If the running sum equals the target (k), update the max length
        // Since this means the entire subarray from the start to the current index has a sum of 0
        if (sum == k) 
            length = max(length, i + 1);

        // If this sum hasn't been seen before, store its index in the map
        if (mp.find(sum) == mp.end()) 
            mp[sum] = i;

        // Check if there exists a prefix with a sum that would make the current subarray sum equal to k
        if (mp.find(sum - k) != mp.end()) 
            length = max(length, i - mp[sum - k]);
    }

    return length; // Return the maximum length of the subarray with sum 0
    }

};




//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends
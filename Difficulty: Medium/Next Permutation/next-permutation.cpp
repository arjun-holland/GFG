//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// time complexity : O(n)

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
     int id = -1; 

    // Step 1: Find the largest index 'id' such that arr[id] < arr[id + 1]
    for(int i = arr.size() - 1; i >= 1; i--) {
        if(arr[i - 1] < arr[i]) { 
            id = i - 1; 
            break; 
        }
    }

    // Step 2: If no such index exists, it means we are at the (greatest permutation [3,2,1]) last permutation
    if(id == -1) {
        reverse(arr.begin(), arr.end()); // Reverse the entire array to get the smallest permutation
        return; 
    }

    // Step 3: Find the largest index 'j' greater than 'id' such that arr[j] > arr[id]
    for(int i = arr.size() - 1; i > id; i--) {
        if(arr[i] > arr[id]) {
            swap(arr[i], arr[id]);
            break; 
        }
    }

    // Step 4: Reverse the subarray from id + 1 to end to get the next permutation
    reverse(arr.begin() + id + 1, arr.end());
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
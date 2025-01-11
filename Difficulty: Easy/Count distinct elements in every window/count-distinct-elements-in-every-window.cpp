//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> ans;
    unordered_map<int, int> freq; // To track frequency of elements
    int distinctCount = 0;

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        if (freq[arr[i]] == 0) {
            distinctCount++;
        }
        freq[arr[i]]++;
    }
    ans.push_back(distinctCount);

    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove the element going out of the window
        if (freq[arr[i - k]] == 1) {
            distinctCount--;
        }
        freq[arr[i - k]]--;

        // Add the new element coming into the window
        if (freq[arr[i]] == 0) {
            distinctCount++;
        }
        freq[arr[i]]++;

        ans.push_back(distinctCount);
    }

    return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
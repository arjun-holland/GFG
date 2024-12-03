//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*O(n + m), where n is the length of the text 
and m is the length of the pattern*/

class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        int k = pat.size();
        vector<int> lps(k, 0); // LPS array initialization
        int len = 0;

        // Step 1: Build LPS array --largest prefix and suffix
        for (int i = 1; i < k;) {
            if (pat[i] == pat[len]) {
                lps[i] = len + 1;
                i++;
                len++;
            } else if (len) {
                len = lps[len - 1]; // Use previous LPS value
            } else {
                i++; // No prefix-suffix match
            }
        }

        vector<int> ans; // To store starting indices of matches
        // Step 2: Search for pattern in text
        for (int i = 0, j = 0; i < txt.size(); ) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
                if (j == k) { // Found a match
                    ans.push_back(i - j); // Store start index
                    j = lps[j - 1]; // Update j using LPS
                }
            } else {
                if (j) {
                    j = lps[j - 1]; // Use LPS to skip comparisons
                } else {
                    i++; // Move to next character in text
                }
            }
        }
        return ans; // Return all starting indices of matches
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
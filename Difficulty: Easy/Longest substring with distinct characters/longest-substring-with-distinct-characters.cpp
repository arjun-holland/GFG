//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
    
        int a = 0;
        int i = 0, n = s.size();
        while (i < n) {
            set<char> st;
            int j = i;
            while (j < n && st.count(s[j]) == 0) { // Check if the character is not in the set
                st.insert(s[j]);
                j++;
            }
            a = max(a, static_cast<int>(st.size())); // Explicit cast to int
            i++;
        }
        return a; // Return the result
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
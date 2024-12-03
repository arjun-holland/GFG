//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        string tot = s + "*" + rev;
        int k = tot.size();
        
        vector<int> lps(k, 0); // LPS array initialization
        int len = 0;
        //Build LPS array -- Longest prefix and suffix
        for (int i = 1; i < k;) {
            if (tot[i] == tot[len]) {
                lps[i] = len + 1;
                i++;
                len++;
            } else if (len) {
                len = lps[len - 1]; // Use previous LPS value
            } else {
                i++; // No prefix-suffix match
            }
        }
        return s.size() - lps[k-1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string expandFromCenter(string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string &s) {
        if (s.empty()) return "";
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            
            // Odd length palindrome
            string odd = expandFromCenter(s, i, i);
            if (odd.length() > res.length()) res = odd;

            // Even length palindrome
            string even = expandFromCenter(s, i, i + 1);
            if (even.length() > res.length()) res = even;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
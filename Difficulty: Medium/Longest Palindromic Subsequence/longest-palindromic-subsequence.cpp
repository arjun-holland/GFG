//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int n,m;
    int t[1001][1001];
    int solve(string &s1,string &s2,int i,int j){
        if(i >= n || j >= m)return 0;
        
        if(t[i][j] != -1)return t[i][j];
        if(s1[i] == s2[j]){
            return t[i][j] = 1+solve(s1,s2,i+1,j+1);
        }
        return t[i][j] = max(solve(s1,s2,i+1,j),solve(s1,s2,i,j+1));
    }
    int lcs(string &s1, string &s2) {
        // code here
        n = s1.length();
        m = s2.length();
        memset(t,-1,sizeof(t));
        return solve(s1,s2,0,0);
    }
  
    int longestPalinSubseq(string &s) {
        string rs = s;
        reverse(s.begin(),s.end());
        return lcs(s,rs);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
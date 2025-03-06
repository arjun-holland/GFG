//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
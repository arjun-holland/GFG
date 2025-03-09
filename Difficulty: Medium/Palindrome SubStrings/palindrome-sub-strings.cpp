//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int solve(string &s,int l,int r){
        int c = 0;
        while(l>=0 && r<s.length() && s[l] == s[r]){
            if(r-l != 0)c++;
            l--;
            r++;
        }
        return c;
    }
    
    int countPS(string &s) {
        // code here
        int oddcount = 0;
        int evencount = 0;
        
        for(int i=0;i<s.length();i++){
            oddcount += solve(s,i,i);
            evencount += solve(s,i,i+1);
        }
        return oddcount+evencount;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
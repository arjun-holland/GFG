//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//   public:
//     int maxLength(string& s) {
//         // code here
//     }
// };
// // User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int m = 0;
        stack<int> s;
        s.push(-1);
        for(int i = 0;i<str.size();i++){ 
            if(str[i]=='(') s.push(i);   //'('
            else{                        //')' 
                s.pop();
                if(s.empty())s.push(i);
                else{
                    int len = i-s.top();
                    m = max(m,len);
                }
            }
        }
        return m;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
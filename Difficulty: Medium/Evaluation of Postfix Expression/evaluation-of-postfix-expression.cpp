//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for(string& c : arr) {
            // Check if it's a number (including negative numbers)
            if (!c.empty() && (isdigit(c[0]) || (c[0] == '-' && c.size() > 1 && all_of(c.begin() + 1, c.end(), ::isdigit)))) {
                st.push(stoi(c));  // Convert string to int and push
            }
            else if (st.size() >= 2) {  // Ensure stack has enough elements before popping
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                if (c == "+") {
                    st.push(b + a);
                } else if (c == "-") {
                    st.push(b - a);  // Fixing order: b - a
                } else if (c == "*") {
                    st.push(b * a);
                } else if (c == "/") {
                    st.push(b / a);  // Fixing order: b / a
                }
            }
        }
        
        return st.empty() ? 0 : st.top();  // Edge case: return 0 if stack is empty
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
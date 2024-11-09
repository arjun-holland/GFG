//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  string minSum(vector<int> &arr) {
        
    string n1 = "", n2 = "";
    sort(arr.begin(), arr.end());

    // Distributing digits into n1 and n2
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            n1 += to_string(arr[i]);
        } else {
            n2 += to_string(arr[i]);
        }
    }

    // Reverse to get correct order
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    // Adding n1 and n2
    int i = 0, j = 0, carry = 0;
    string ans = "";

    while (i < n1.length() || j < n2.length() || carry) {
        int sum = carry;
        
        if (i < n1.length()) {
            sum += n1[i++] - '0';//string:char to int
        }
        if (j < n2.length()) {
            sum += n2[j++] - '0';
        }

        carry = sum / 10;
        ans += to_string(sum % 10);
    }

    // Reverse result to get final answer
    reverse(ans.begin(), ans.end());
    
    // Remove leading zeros if any
    while (ans.size() > 1 && ans[0] == '0') {
        ans.erase(ans.begin());
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
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
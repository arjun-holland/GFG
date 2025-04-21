//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size()+1;
        vector<int> ans(n,0);
        for(int e : arr){
            ans[e-1] = e;
        }
        for(int i=0;i<n;i++){
            if(ans[i] == 0)return i+1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
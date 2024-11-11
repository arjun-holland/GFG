//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        sort(arr.begin(),arr.end());
        int res = 0;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] < arr[i+1]){
                continue;
            }
            int d = arr[i]-arr[i+1];
            res += d+1;
            arr[i+1] = arr[i+1]+d+1; 
        }
        return res;
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
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n=arr.size();
        vector<int> l(n,0),r(n,0);
        l[0] = arr[0];
        for(int i=1;i<n;i++){
            l[i] = max(arr[i],l[i-1]);
        }
        r[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            r[i] = max(arr[i],r[i+1]);
        }
        int wt = 0;//water trapped
        for(int i=0;i<n;i++){
            int wl = min(l[i],r[i]);//water level
            wt += abs(wl-arr[i]);
        }
        return wt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
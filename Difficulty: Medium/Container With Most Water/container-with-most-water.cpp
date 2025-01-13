//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int l = 0,r = arr.size()-1;
        int mw = 0;
        while(l < r){
            int cwm = min(arr[l],arr[r])*(r-l);
            mw = max(mw, cwm);
            if(arr[l] < arr[r])l++;
            else r--;
        }
        return mw;
    }
};
//two pointer approach

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
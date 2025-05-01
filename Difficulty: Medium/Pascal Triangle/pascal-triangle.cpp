//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int solve(int r,int c){
        int res = 1;
        for(int i=0;i<c;i++){
            res = res*(r-i);
            res = res/(i+1);
        }
        return res;
    }
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++){
            ans.push_back(solve(n-1,i-1));
        }
        return ans;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumProfit(vector<int> &p) {
        // code here
        int ans = 0,j = 0,i = 0;
        int n = p.size()-1;
        while(j < n){
            if(p[j] < p[j+1]){
                j++;
                continue;
            }
            ans += (p[j]-p[i]);
            j++;
            i=j;
        }
        ans += (p[j]-p[i]);
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
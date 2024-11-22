//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &p) {
        // code here
        /*int a = 0;
        for(int i=0;i<p.size();i++){
            for(int j=i+1;j<p.size();j++){
                if(p[j] > p[i]){
                    a = max(a,p[j]-p[i]);
                }
            }
        }
        return a;*/
        int a = 0, b = INT_MAX;
        for(int &s : p){
            if(b > s)
               b = s;
            a = max(a,s-b);
        }
        return a;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPossible(int m,vector<int>& stalls,int k){
        int c = 1;
        int ep = stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - ep >= m){
                c++;
                ep = stalls[i];
                if(c>=k) return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k){
        sort(begin(stalls),end(stalls));
        int l = 0;
        int r = stalls[stalls.size()-1]-stalls[0];
        int res = 0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(isPossible(m,stalls,k)){
                res = m;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
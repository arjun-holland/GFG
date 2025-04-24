//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int r = 0;//XOR RESULT
        for(int e : arr){
            r = r ^ e;
        }
        //int sb = r & -r; // used to isolate the right most set-bit in XOR
        int pos = 0;// brute force way used to isolate the right most set-bit in XOR
        while((r & 1) == 0){
            pos++;
            r >>= 1;
        }
        int g1=0,g2=0;
        for(int e : arr){
            if(e & (1 << pos))g1 = g1 ^ e;
            else g2 = g2 ^ e;
        }
        if(g2 < g1)return {g2,g1};
        return {g1,g2};
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        unordered_map<int,int> fs;//first occurrance
        fs[0] = -1;
        int sum = 0,res = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] > k)sum++;
            else sum--;
            if(sum > 0)res = max(res,i+1);
            else if(fs.find(sum-1) != fs.end()){
                res = max(res,i-fs[sum-1]);
            }else if(fs.find(sum) == fs.end()){
                fs[sum] = i;
            }
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        stack<int> s;
        s.push(-1);
        vector<int> res(arr.size(),1);
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && s.top() != -1 && arr[s.top()] <= arr[i]){
                s.pop();
            }
            if(!s.empty()){
                res[i] = i - s.top(); 
            }
            s.push(i);
        }
        return res;
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
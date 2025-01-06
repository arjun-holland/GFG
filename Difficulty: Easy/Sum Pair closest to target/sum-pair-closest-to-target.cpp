//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        vector<int> r;
        if(arr.size()==1)return {};
        sort(arr.begin(),arr.end());
        int d = INT_MAX;
        int i =0 , j = arr.size()-1;
        while(i<j){
            int dd = abs((arr[i]+arr[j])-target);
            if(dd == 0)return {arr[i],arr[j]};
            if(dd < d){
                d = dd;
                r = {arr[i],arr[j]};
            }
            if((arr[i]+arr[j]) > target){
                j--;
            }else{
                i++;
            }
        }
        return r;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        vector<int> a;
        sort(arr.begin(),arr.end());//
        int n = arr.size()/3;
        int cc = 1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                cc++;
            }else{
                if(cc > n)a.push_back(arr[i]);
                cc = 1;
            }
        }
        if(cc > n)a.push_back(arr[arr.size()-1]);
        return a;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
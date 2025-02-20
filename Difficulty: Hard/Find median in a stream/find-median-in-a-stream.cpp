//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double> ans;
        priority_queue<int> mxh;
        priority_queue<int,vector<int>,greater<int>> mih;
        
        for(int e : arr){
            if(mxh.empty() || e <= mxh.top()) mxh.push(e);
            else mih.push(e);
            
            if(mxh.size() > mih.size()+1){
                mih.push(mxh.top());
                mxh.pop();
            }else if(mih.size() > mxh.size()){
                mxh.push(mih.top());
                mih.pop();
            }
            
            if(mih.size() == mxh.size())
               ans.push_back((mih.top()+mxh.top())/2.0);
            else ans.push_back(mxh.top());
        }
        return ans;
    }
};
// As we need to maintain tha order for every insertion in the arr we hve to use the heap DS 


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
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
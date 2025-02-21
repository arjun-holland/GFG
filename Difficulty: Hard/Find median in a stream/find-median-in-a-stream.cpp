//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> mx; // max ele in left side
        priority_queue<int,vector<int>,greater<int>> mi; // min ele in right side
        
        vector<double> res;
        for(int e : arr){
            mx.push(e);
            mi.push(mx.top());
            mx.pop();
            if(mi.size() > mx.size()){
                mx.push(mi.top());
                mi.pop();
            }
            if(mx.size() == mi.size()){
                res.push_back((mx.top()+ mi.top())/2.0);
            }else{
                res.push_back(mx.top());
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
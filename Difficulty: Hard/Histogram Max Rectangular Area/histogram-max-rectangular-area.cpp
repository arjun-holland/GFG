//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        stack<int> st;//near smallestr left element
        vector<int> nsl(arr.size(),0);
        
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                nsl[i] = -1;
            }
            else if(arr[i] > arr[st.top()]){
                nsl[i] = st.top();
            }
            else{
                while(!st.empty() && arr[i] <= arr[st.top()])
                   st.pop();
                if(st.empty())
                   nsl[i] = -1;
                else
                   nsl[i] = st.top();                  
            }
            st.push(i);
        }
        vector<int> nsr(arr.size(),0);
        stack<int> stt;
        
        for(int i=arr.size()-1;i>=0;i--){
            if(stt.empty()){
                nsr[i] = arr.size();
            }
            else if(arr[i] > arr[stt.top()]){
                nsr[i] = stt.top();
            }
            else{
                while(!stt.empty() && arr[i] <= arr[stt.top()])
                   stt.pop();
                if(stt.empty())
                   nsr[i] = arr.size();
                else
                   nsr[i] = stt.top(); 
            }
            stt.push(i);
        }
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            int v = arr[i] * (nsr[i] - nsl[i] - 1);
            ans = max(ans,v);
        }
        return ans;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
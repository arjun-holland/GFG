//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int s = 0;
        int ml = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            s += arr[i];
            if(s==0){
                ml = max(ml,i+1);
            }
            else if(mp.find(s)!=mp.end()){
                ml = max(ml,i-mp[s]);
            }else{
                mp[s]=i;
            }
        }
        return ml;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
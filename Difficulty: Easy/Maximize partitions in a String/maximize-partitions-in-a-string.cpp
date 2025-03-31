//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]] = i; //mp[char] = last_index of that char
        }
        int res = 0,curMaxInd = 0;
        for(int j=0; j<s.length(); j++){
            curMaxInd = max(curMaxInd,mp[s[j]]);
            if(j == curMaxInd){
                res++;
                curMaxInd = j+1;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
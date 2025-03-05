//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool sortBylength(string &a,string &b){
        return a.length() < b.length();
    }
    int longestStringChain(vector<string>& words) {
        // Code here
        unordered_map<string,int> dp;
        sort(words.begin(),words.end(),sortBylength);
        int ans = 0;
        for(string &word : words){
            int v = 0;
            for(int i=0;i<word.length();i++){
                string predecessor = word.substr(0,i) + word.substr(i+1);
                if(dp.find(predecessor) != dp.end()){
                    v = max(v,dp[predecessor]);
                }
                
                
            }
            dp[word] = v + 1;
            ans = max(ans,dp[word]);
        }
        return ans;
    }
};
/*
The predecessor of a word is another word that can be formed by removing exactly one character from the original word.
For example, for the word "bca", the possible predecessors are "ba", "ca", and "bc".*/

/*
By default, in an unordered map, if the key doesn't exist, 
it will insert that key with a default value, which is 0 for an int.
*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
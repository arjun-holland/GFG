//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
       /* sort(citations.begin(),citations.end());
        int n = citations.size();
        int res = 0;
        for(int i=0;i<n;i++){
            int h = n - i;
            if(citations[i] >= h)
              return citations[i];
        }
        return 0;
        
        */
        int n = citations.size();
        vector<int> in(n+1,0);
        for(int i=0;i<n;i++){
            if(citations[i] >= n)
              in[n]++;
            else  
              in[citations[i]]++;
        }
        int ans = 0;
        for(int i = n;i>=0;i--){
            ans += in[i];
            if(ans >= i)return i;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
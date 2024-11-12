//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Complete back-end function template for C++


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long> productExceptSelf(vector<int>& arr) {
        // code here
        vector<long long> re;
        for(int i=0;i<arr.size();i++){
            long long ans = 1;
            for(int j=0;j<arr.size();j++){
                if(i != j){
                    ans *= arr[j];
                }
            }
            re.push_back(ans);
        }
        return re;
    }
};


//{ Driver Code Starts.

int main() {

    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // To ignore newline character after t input

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
        vector<long long> vec = obj.productExceptSelf(arr); // Function call

        for (int i = 0; i < vec.size(); i++) { // Print the output
            cout << vec[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
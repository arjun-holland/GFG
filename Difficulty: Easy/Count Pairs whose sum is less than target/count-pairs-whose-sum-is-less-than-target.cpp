//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        /*int a =0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]+arr[j]<target)
                  a++;
            }
        }
        return a;*/
        std::sort(arr.begin(), arr.end()); // Sort the array first
        int count = 0;
        int left = 0, right = arr.size() - 1;

        while (left < right) {
           if (arr[left] + arr[right] < target) {
             count += (right - left); // All pairs from `left` to `right - 1` will have sum < target
             left++;
           } else {
             right--; // Reduce the range if the sum is >= target
           }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
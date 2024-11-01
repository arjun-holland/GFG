//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<long long> re;
        long long n = arr.size();
        // Fill re with alternating smallest and largest elements
        for (int i = 0; i < n / 2; i++) {
            re.push_back(arr[i]);           // Smallest elements
            re.push_back(arr[n - i - 1]);   // Largest elements
        }
        
        // If n is odd, add the middle element
        //if (n % 2 != 0) {
        //    re.push_back(arr[n / 2]);
        //}
        long long r = 0;
        for(int i=0; i<re.size()-1;i++){
            r += abs(re[i+1]-re[i]);//1 8 2 4 =7+6+2+3
        }
        r += re[re.size()-1]-re[0];
        return r;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
   vector<int> findSplit(vector<int>& arr) {
    vector<int> a;
    int sum = 0;
    
    // Calculate the total sum of the array
    for(int &x : arr) sum += x;
    
    // If sum is not divisible by 3, we cannot split it into 3 equal parts
    if(sum % 3 != 0) return {-1, -1};
    
    int eachPartSum = sum / 3;
    int cursum = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        cursum += arr[i];
        
        // Check if the current sum matches the target sum for each part
        if(cursum == eachPartSum) {
            a.push_back(i);
            cursum = 0; // Reset cursum after finding each part
            
            // If we have found 2 splits, we can return the indices
            if(a.size() == 2) return a;
        }
    }
    
    // If less than 2 splits are found, return {-1, -1}
    return {-1, -1};
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
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1 || result.size() != 2) {
            cout << "false" << endl;
        } else {
            int sum1 = 0, sum2 = 0, sum3 = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (i <= result[0])
                    sum1 += arr[i];

                else if (i <= result[1])
                    sum2 += arr[i];

                else
                    sum3 += arr[i];
            }
            if (sum1 == sum2 && sum2 == sum3) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
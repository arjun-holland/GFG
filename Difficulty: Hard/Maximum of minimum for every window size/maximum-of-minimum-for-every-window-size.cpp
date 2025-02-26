//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        /*
        // return ans;
        int n = arr.size();
        vector<int> ans(n, 0);
        
        // For window size = 1 (max of all elements)
        ans[0] = *max_element(arr.begin(), arr.end());
        
        // For window size = n (min of all elements)
        ans[n - 1] = *min_element(arr.begin(), arr.end());

        int k = 2;
        while (k <= n) {
            vector<int> minValues;
            
            for (int i = 0; i <= n - k; i++) {  // Fix: Prevent out-of-bounds access
                int mv = *min_element(arr.begin() + i, arr.begin() + i + k);
                minValues.push_back(mv);
            }
            
            ans[k - 1] = *max_element(minValues.begin(), minValues.end());
            k++;
        }
        
        return ans;
        */
         int n = arr.size();
        vector<int> ans(n, 0);
        vector<int> left(n, -1), right(n, n);
        
        stack<int> s;
        
        // Finding previous smaller element for each element
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                left[i] = s.top();
            s.push(i);
        }
        
        while (!s.empty()) s.pop();
        
        // Finding next smaller element for each element
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                right[i] = s.top();
            s.push(i);
        }
        
        // Storing the result for each window size
        vector<int> temp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int windowSize = right[i] - left[i] - 1;
            temp[windowSize] = max(temp[windowSize], arr[i]);
        }
        
        // Filling unfilled values by propagating max values from right to left
        for (int i = n - 1; i >= 1; i--)
            temp[i] = max(temp[i], temp[i + 1]);
        
        return vector<int>(temp.begin() + 1, temp.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
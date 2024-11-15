//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


// User function template 
class Solution {
public:
    // Function returns the second largest element
    int getSecondLargest(vector<int> &arr) {
        // Use a set to store unique elements
        set<int> uniqueElements(arr.begin(), arr.end());
        
        // If there are less than 2 unique elements, return -1
        if (uniqueElements.size() < 2) {
            return -1;
        }

        // Create a min-heap (priority queue)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Push unique elements into the min-heap
        for (int num : uniqueElements) {
            minHeap.push(num);
            // Maintain only top 2 largest elements in the heap
            if (minHeap.size() > 2) {
                minHeap.pop();
            }
        }

        // The second largest will be at the root of the min-heap
        return minHeap.top();
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
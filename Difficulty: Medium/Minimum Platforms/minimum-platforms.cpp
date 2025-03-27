//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
        int platforms = 0, maxPlatforms = 0;

        for (int i = 0; i < arr.size(); i++) {
            while (!pq.empty() && pq.top() < arr[i]) {
                pq.pop(); // Train departs, free a platform
            }
            pq.push(dep[i]); // Add new train's departure time
            maxPlatforms = max(maxPlatforms, (int)pq.size()); // Track max platforms needed
        }
        return maxPlatforms;
    }
};






//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
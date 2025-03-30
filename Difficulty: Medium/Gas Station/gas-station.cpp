//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// class Solution {
// public:
//     int startStation(vector<int> &gas, vector<int> &cost) {
//         int n = gas.size();
        
//         // Step 1: Extend arrays to simulate circular route
//         for (int i = 0; i < n - 1; i++) {
//             gas.push_back(gas[i]);
//             cost.push_back(cost[i]);
//         }

//         // Step 2: Try starting from each index
//         for (int i = 0; i < n; i++) {
//             int currentGas = 0;
//             bool valid = true;

//             // Step 3: Travel n stations from the starting index
//             for (int j = i; j < i + n; j++) {
//                 currentGas += gas[j] - cost[j];
                
//                 // Step 4: If gas goes negative, current start fails
//                 if (currentGas < 0) {
//                     valid = false;
//                     break;
//                 }
//             }

//             // Step 5: Return index if valid
//             if (valid) return i;
//         }

//         // Step 6: No valid start found
//         return -1;
//     }
// };
class Solution {
public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int totalGas = 0, totalCost = 0, currentGas = 0;
        int startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            // If current gas balance drops below zero, reset the starting index
            if (currentGas < 0) {
                startIndex = i + 1; // Start from next station
                currentGas = 0;
            }
        }

        // Check if the circuit can be completed
        return (totalGas >= totalCost) ? startIndex : -1;
    }
};




//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
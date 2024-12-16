//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i = 0, j = 0;  // Pointers for arrays a and b
        int count = 0;     // Counter for the number of elements processed
        int result = -1;   // Placeholder for the k-th element
        // Traverse both arrays
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                result = a[i];
                i++;
            } else {
                result = b[j];
                j++;
            }
            count++; // Increment count
            
            // If we reach the k-th element
            if (count == k) return result;
        }
        // If elements remain in array a
        while (i < a.size()) {
            result = a[i];
            i++;
            count++;
            if (count == k) return result;
        }
        // If elements remain in array b
        while (j < b.size()) {
            result = b[j];
            j++;
            count++;
            if (count == k) return result;
        }
        return result; // Return the k-th element
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends
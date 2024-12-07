//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    void merge(vector<int>& arr, int s, int e, int m, int &r) {
        int left = s, right = m + 1;
        vector<int> temp;

        while (left <= m && right <= e) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                r += (m - left + 1); // Count inversions.
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Add remaining elements.
        while (left <= m) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= e) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = s; i <= e; i++) {
            arr[i] = temp[i - s];
        }
    }

    // Function to perform merge sort and count inversions.
    void mergeSort(vector<int>& arr, int s, int e, int &r) {//
        if (s >= e) return;
        int m = s + (e - s) / 2;
        
        mergeSort(arr, s, m, r);
        mergeSort(arr, m + 1, e, r);
        
        merge(arr, s, e, m, r);
    }

    int inversionCount(vector<int> &arr) {
       /* int r =0;
        for(int i=0;i<arr.size();i++){ //10^5*10^5 == 10^10 > 10^5 TLE
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j])
                   r++;
            }
        }
        return r; */
        int r = 0;
        mergeSort(arr,0,arr.size()-1,r);
        return r;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
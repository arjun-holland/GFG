//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int r =0;
        for(int i=0;i<=arr.size()-3;i++){
            int j=i+1, k = arr.size()-1;
            while(j<k){
                int s = arr[i]+arr[j]+arr[k];
                if(s>target)k--;
                else if(s<target)j++;
                else{
                    r++;
                    int temp = j+1;
                    while(temp<k && arr[temp]==arr[temp-1])r++,temp++;
                    k--;
                }
            }
        }
        return r;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
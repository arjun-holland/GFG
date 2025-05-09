//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool isDecreasing(vector<int>  & arr){
        vector<int> s = arr;
        sort(s.begin(),s.end());
        return s == arr;
    }
    int findMissing(vector<int> &arr) {
        int cd = INT_MAX;//common diff
        for(int i=1;i<arr.size();i++){
            int d = abs(arr[i]-arr[i-1]);
            if(d < cd)cd = d;
        }
        int e = -1;
        
        if(!isDecreasing(arr)){
            for(int i=0;i<arr.size()-1;i++){
                if(abs(arr[i]-arr[i+1]) > cd){
                    e = arr[i] - cd;
                    break;
                }
            }
            if(e == -1){
                return arr[arr.size()-1]-cd;
            }
            return e;
        }
        for(int i=0;i<arr.size()-1;i++){
            if(abs(arr[i]-arr[i+1]) > cd){
                e = arr[i] + cd;
                break;
            }
        }
        if(e == -1)e = arr[arr.size()-1]+cd;
        return e;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
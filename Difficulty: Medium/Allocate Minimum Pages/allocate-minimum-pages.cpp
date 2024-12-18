//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(int m,vector<int>& arr,int k){
        int number = 1,pages = 0;
        for(int e: arr){
            if(e>m)return false;
            if(pages+e > m){
                number++;//just gave my previous pages to one studejnt
                pages=e;//update the pages 
            }else{
                pages+=e;
            }
        }
        if(number <= k)return true;
        return false;
    }
  
    int findPages(vector<int> &arr, int k) {
        if(arr.size()<k)return -1;
        int l=0,r=0;
        for(int e:arr)r+=e;
        int ans = -1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(m,arr,k)){
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int v = 0,me = arr[0];
        for(int i:arr){
            if(me == i){
                v++;
            }else{
                v--;
                if(v==0){
                    me = i;
                    v++;
                }
            }
        }
        int c = 0;
        for(int e : arr){
            if(e == me)c++;
        }
        if(c > (arr.size()/2))return me;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
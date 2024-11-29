//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& a, string& b) {
         if(a.length()!=b.length()){
            while(a.length()>b.length()){
                b.insert(0, "0");
            }
             while(b.length()>a.length()){
                a.insert(0, "0");
            }
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        char carry = '0';
        string res = "" ;
        for(int i=0; i<a.size(); i++){//o(n)
            if(a[i]=='0' && b[i]=='0' && carry == '0' )res.push_back('0');
            else if((a[i]=='1' && b[i]=='1' && carry == '0')||(a[i]=='0' && b[i]=='1' && carry == '1')||(a[i]=='1' && b[i]=='0' && carry == '1')){
                res.push_back('0');
                carry = '1';
            }
            else if(a[i]=='1' && b[i]=='1' && carry == '1'){
                res.push_back('1');
                carry = '1';
            }
            else{
                res.push_back('1');
                if(carry == '1')carry ='0';
            }
        }
        if(carry=='1') res.push_back('1');
        reverse(res.begin(),res.end());
        while(!res.empty() && res[0] == '0') {
            res.erase(res.begin());
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
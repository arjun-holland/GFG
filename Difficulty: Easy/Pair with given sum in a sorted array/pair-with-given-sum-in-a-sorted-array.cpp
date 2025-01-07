//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int a = 0;
        int i=0,j=arr.size()-1;
        while(i<j){
            int s = arr[i]+arr[j];
            if(s > target)j--;
            else if(s < target)i++;
            else if(s == target){
                int e1 = arr[i],e2 = arr[j],c1=0,c2=0;
                while(i<=j && arr[i] == e1){
                    i++;
                    c1++;
                }
                while(i<=j && arr[j] == e2){
                    j--;
                    c2++;
                }
                if(e1==e2)a+=c1*(c1-1)/2;//hand-shake formula to get pairs
                else a+=c1*c2;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
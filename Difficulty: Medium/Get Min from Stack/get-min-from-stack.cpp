//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int> st,st2;
    
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st.push(x);
        if(st2.empty())st2.push(x);
        else{
            if(st2.top() > x)st2.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty())return;
        int e = st.top();
        st.pop();
        if(e == st2.top())st2.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st.empty())return st.top();
        return -1;
    }
    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st2.empty())return st2.top();
        return -1;
    }
};

/*
4
4
4
3
3
2
3
4
1 15
1 7
*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
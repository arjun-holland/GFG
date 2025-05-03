//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/
class Solution {
  public:
    vector<bool> p;

    Solution() {
        p.resize(100001, true);
        p[0] = p[1] = false;
        seive();
    }

    void seive() {
        for (int i = 2; i * i <= 100000; ++i) {
            if (p[i]) {
                for (int j = i * i; j <= 100000; j += i) {
                    p[j] = false;
                }
            }
        }
    }

    int getData(int n) {
    if (p[n]) return n;

    int lower = n - 1;
    int upper = n + 1;

    while (lower >= 2 && !p[lower]) --lower;
    while (upper <= 100000 && !p[upper]) ++upper;

    // If no lower prime found (e.g., when n = 1), return upper
    if (lower < 2) return upper;

    if (n - lower <= upper - n) return lower;
    return upper;
}


    Node *primeList(Node *head) {
        Node* curr = head;
        while (curr) {
            curr->val = getData(curr->val);
            curr = curr->next;
        }
        return head;
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

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
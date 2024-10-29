//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
public:
    //The partition function separates nodes smaller or equal to p->data into l and others into r.
    void partition(Node* p, Node* &l, Node* &r) {
        Node *t = p->next;
        while (t) {
            Node *nxt = t->next;
            if (t->data <= p->data) {
                t->next = l;
                l = t;
            } else {
                t->next = r;
                r = t;
            }
            t = nxt;
        }
    }
    
    struct Node* quickSort(struct Node* head) {
        if (!head || !head->next) return head;

        Node *l = NULL, *r = NULL;
        partition(head, l, r);
        
        l = quickSort(l);
        r = quickSort(r);

        Node* t = l;// Link left part to head (pivot)
        if (t) {
            while (t->next) t = t->next;
            t->next = head;
        } else {
            l = head;
        }
        head->next = r;// Link head to the right part
        return l;
    }
};
//Average Time Complexity: O(nlogn)
//Worst Time Complexity: 𝑂(𝑛^2)
//Space Complexity:O(logn) on average, O(n) worst case 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

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
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
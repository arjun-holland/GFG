/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        unordered_set<int> seen;
        Node* c = head; //current
        Node* p = nullptr; //prev
        while(c != nullptr){
            if(seen.find(c->data) != seen.end()){
                p->next = c->next;
                delete c;
            }else{
                seen.insert(c->data);
                p = c;
            }
            c = p->next;
        }
        return head;
    }
};
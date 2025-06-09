/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    void solve(Node* r,set<int>& an){
        if(!r)return;
        
        if(r->left)solve(r->left,an);
        an.insert(r->data);
        if(r->right)solve(r->right,an);
    }
    bool res = false;
    void help(Node* r,set<int>& a){
        if(r->left == NULL && r->right == NULL){
            int p = r->data + 1;
            int s = (r->data - 1) == 0? p :r->data - 1;
            if(a.count(p) >= 1 && a.count(s) >= 1){
                res = true;
            }
            return;
        }
        if(!r)return;
        
        if(r->left)help(r->left,a);
        if(r->right)help(r->right,a);
    }
    
    bool isDeadEnd(Node *root) {
        // Code here
        set<int> ans;
        solve(root,ans);
        help(root,ans);
        return res;
    }
};
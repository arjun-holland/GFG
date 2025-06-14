/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool check(Node* r, Node* l) {
        if (!r && !l) return true;        // Both null — symmetric
        if (!r || !l) return false;       // One is null — asymmetric
        if (r->data != l->data) return false; // Values differ — asymmetric

        // Recursively check outer and inner pairs
        return check(r->left, l->right) && check(r->right, l->left);
    }

    bool isSymmetric(Node* root) {
        if (!root || (root->left == NULL && root->right == NULL)) return true;
        return check(root->left, root->right);
    }
};

// Given two binary trees, write a function to check if they are equal or not.
//
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    if (p==NULL && q==NULL) {
        return true;
    }
    if (p==NULL || q==NULL) {
        return false;
    }
    
    if (p->val!=q->val){
        return false;
    }
    else {
        if (!isSameTree(p->left,q->left)) {
            return false;
        }
        else {
            if (!isSameTree(p->right,q->right)) {
                return false;
            }
            else {
                return true;
            }
        }
    }
}

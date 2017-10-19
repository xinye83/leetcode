// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1==NULL && t2==NULL) {
        return true;
    }
    if ((t1==NULL || t2==NULL) || (t1->val != t2->val)) {
        return false;
    }
    
    return isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root==NULL) {
        return true;
    }
    
    return isMirror(root,root);
}

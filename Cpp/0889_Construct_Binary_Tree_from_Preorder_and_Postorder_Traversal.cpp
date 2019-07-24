/*
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

 

Example 1:

Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]
 

Note:

1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return constructFromPrePost(pre, 0, n-1, post, 0, n-1);
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, int l1, int r1, vector<int>& post, int l2, int r2) {
        if (l1 > r1) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[l1]);
        if (l1 < r1) {
            int i = l2;
            while (i <= r2 && pre[l1+1] != post[i]) {
                i++;
            }
            
            root->left = constructFromPrePost(pre, l1+1, i+l1-l2+1, post, l2, i);
            root->right = constructFromPrePost(pre, i+l1-l2+2, r1, post, i+1, r2);
        }
        
        return root;
    }
};

/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root) {
            if (!root->left && !root->right)
                return {to_string(root->val)};
            
            vector<string> ans = {};
            vector<string> temp;
            
            temp = binaryTreePaths(root->left);
            ans.insert(ans.end(),temp.begin(),temp.end());
            
            temp = binaryTreePaths(root->right);
            ans.insert(ans.end(),temp.begin(),temp.end());
            
            vector<string>::iterator it;
            for (it = ans.begin(); it < ans.end(); it++)
                *it = to_string(root->val)+"->"+*it;
            
            return ans;
        }
        else
            return {};
    }
};

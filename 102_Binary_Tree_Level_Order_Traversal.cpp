/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        if (!root->left && !root->right)
            return {{root->val}};
        
        vector<vector<int>> ans;
        if (!root->left)
            ans = levelOrder(root->right);
        else if (!root->right)
            ans = levelOrder(root->left);
        else {
            ans = levelOrder(root->left);
            
            vector<vector<int>> temp = levelOrder(root->right);
            
            for (int i = 0; i < temp.size(); ++i) {
                if (i < ans.size())
                    ans[i].insert(ans[i].end(),temp[i].begin(),temp[i].end());
                else
                    ans.push_back(temp[i]);
            }
        }
        
        ans.insert(ans.begin(),{root->val});
        return ans;
    }
};

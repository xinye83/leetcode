/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return {};
        else if (root->val == sum && !root->left && !root->right)
            return {{root->val}};
        else {
            vector<vector<int>> ans = pathSum(root->left, sum-root->val);
            vector<vector<int>> ans2 = pathSum(root->right, sum-root->val);
            ans.reserve(ans.size()+ans2.size());
            ans.insert(ans.end(),ans2.begin(),ans2.end());
            
            for (int i = 0; i < ans.size(); i++)
                ans[i].insert(ans[i].begin(),root->val);
            
            return ans;
        }
    }
};

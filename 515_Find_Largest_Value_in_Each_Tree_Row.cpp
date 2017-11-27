/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> v;
        v.push_back(largestValues(root->left));
        v[0].insert(v[0].begin(),root->val);
        v.push_back(largestValues(root->right));
        v[1].insert(v[1].begin(),root->val);
        
        int i,j;
        if (v[0].size()>v[1].size())
            i = 0;
        else
            i = 1;
        
        j = 1-i;
        
        for (int k = 1; k < v[j].size(); ++k)
            v[i][k] = max(v[i][k],v[j][k]);
        
        return v[i];
    }
};

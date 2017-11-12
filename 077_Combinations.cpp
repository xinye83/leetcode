/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (!k || n < k)
            return {{}};
        if (n == k) {
            vector<int> ans(n);
            for (int i = 0; i < n; )
                ans[i] = ++i;
            
            return {ans};
        }
        
        vector<vector<int>> ans = combine(n-1,k-1);
        for (int i = 0; i < ans.size(); i++)
            ans[i].push_back(n);
        
        vector<vector<int>> temp = combine(n-1,k);
        ans.insert(ans.end(),temp.begin(),temp.end());
        
        return ans;
    }
};

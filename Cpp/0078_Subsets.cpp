/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        
        for (int i = 0; i < nums.size(); ++i) {
            int n = ans.size();
            
            for (int j = 0; j < n; ++j) {
                vector<int> temp = ans[j];
                
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};

/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        return permute(nums, 0);
    }
    
    vector<vector<int>> permute(vector<int>& nums, int index) {
        if (index == nums.size()-1) {
            return {{nums[index]}};
        }
        
        vector<vector<int>> next = permute(nums, index+1);
        vector<vector<int>> ans;
        
        for (int i = 0; i < next.size(); ++i) {            
            for (int j = 0; j <= next[i].size(); ++j) {
                vector<int> temp = next[i];
                
                temp.insert(temp.begin()+j, nums[index]);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};

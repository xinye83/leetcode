/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4)
            return {};
        
        sort(nums.begin(), nums.end());
        
         vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int start = j+1, end = n-1;
                while (start < end) {                    
                    if (nums[i]+nums[j]+nums[start]+nums[end] == target) {
                        ans.push_back({nums[i],nums[j],nums[start],nums[end]});
                        
                        while (start < end && nums[start] == nums[start+1])
                            start++;
                        while (start < end && nums[end] == nums[end-1])
                            end--;
                        
                        start++;
                        end--;
                    }
                    else if (nums[i]+nums[j]+nums[start]+nums[end] < target)
                        start++;
                    else
                        end--;
                }
                
                while (j < n-1 && nums[j] == nums[j+1])
                    ++j;
            }
            
            while (i < n-1 && nums[i] == nums[i+1])
                ++i;
        }
        
        return ans;
    }
};

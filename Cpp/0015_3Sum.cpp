/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int l = i+1, r = n-1;
            while (l < r) {
                int sum = nums[i]+nums[l]+nums[r];
                
                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    
                    while (l < r && nums[l] == nums[l+1])
                        l++;
                    while (l < r && nums[r] == nums[r-1])
                        r--;
                    
                    l++;
                    r--;
                }
            }
        }
        
        return ans;
    }
};

/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        sort(nums.begin(), nums.end());
        
        int ans = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            int left = i+1;
            int right = nums.size()-1;
            
            int sum;
            while (left < right) {
                int sum = nums[i]+nums[left]+nums[right];
                
                if (abs(sum-target) < abs(ans-target))
                    ans = sum;
                
                if (sum == target)
                    return ans;
                else if (sum > target)
                    right--;
                else
                    left++;
            }
        }
        
        return ans;
    }
};

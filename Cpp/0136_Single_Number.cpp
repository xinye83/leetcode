/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        
        int i = 0;
        int j = nums.size()-1;
        
        while (j-i > 2) {
            int k = (i+j)/2;
            
            if (nums[k] != nums[k-1] && nums[k] != nums[k+1])
                return nums[k];
            else if (nums[k] == nums[k-1]) {
                if ((k-i+1)%2)
                    j = k-2;
                else
                    i = k+1;
            }
            else {
                if ((j-k)%2)
                    j = k-1;
                else
                    i = k+2;
            }
        }
        
        if (i == j)
            return nums[i];
        
        return (nums[i] == nums[i+1]) ? nums[j]: nums[i];
    }
};

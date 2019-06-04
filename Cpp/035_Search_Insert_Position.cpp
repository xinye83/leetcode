/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2

Example 2:

Input: [1,3,5,6], 2
Output: 1

Example 3:

Input: [1,3,5,6], 7
Output: 4

Example 1:

Input: [1,3,5,6], 0
Output: 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.front() >= target)
            return 0;
        if (nums.back() < target)
            return nums.size();
        if (nums.back() == target)
            return nums.size()-1;
        
        int x = 0;
        int y = nums.size()-1;
        
        while (y-x > 1) {
            int z = (x+y)/2;
            
            if (nums[z] == target)
                return z;
            else if (nums[z] > target)
                y = z;
            else
                x = z;
        }
        
        return y;
    }
};

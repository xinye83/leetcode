/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i1 = 0;
        int i2 = nums.size()-1;
        
        if (i2 == 0)
            return 0;
        
        while (i2-i1 > 1) {
            int i = (i1+i2)/2;
            
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
            else if (nums[i] > nums[i+1])
                i2 = i-1;
            else
                i1 = i+1;
        }
        
        return nums[i1] > nums[i2] ? i1 : i2;
    }
};

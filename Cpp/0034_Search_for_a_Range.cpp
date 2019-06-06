/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty() || nums.front() > target || nums.back() < target)
            return {-1,-1};
        
        int a;
        int b;
        
        if (nums.front() == target)
            a = 0;
        else {
            int x = 0;
            int y = nums.size()-1;
            
            while (y-x > 1) {
                int z = x + (y-x)/2;
                
                if (nums[z] < target)
                    x = z;
                else
                    y = z;
            }
            
            if (nums[y] != target)
                return {-1,-1};
            else
                a = y;
        }
        
        if (nums.back() == target)
            b = nums.size()-1;
        else {
            int x = a;
            int y = nums.size()-1;
            
            while (y-x > 1) {
                int z = x + (y-x)/2;
                
                if (nums[z] > target)
                    y = z;
                else
                    x = z;
            }
            
            b = x;
        }
        
        return {a,b};
    }
};

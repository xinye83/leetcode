/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int m = 0; // maximum distance
        
        for (int i = 0; i < n; ++i) {
            if (i > m)
                return 0;
            else 
                m = max(m,i+nums[i]);
            
            if (m >= n-1)
                return 1;
        }
    }
};

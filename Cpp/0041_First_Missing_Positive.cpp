/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int temp1, temp2, i, n = nums.size();
        
        for (i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = -1;
        }
        
        i = 0;
        // 0: exist
        // -1: not
        while (i < n) {
            if ( nums[i] > 0 ) {
                temp1 = i;
                temp2 = nums[i];
                nums[i] = -1;
                do {
                    temp1 = temp2;
                    temp2 = nums[temp1-1];
                    nums[temp1-1] = 0;
                } while (temp2 > 0);
            }
            
            i++;
        }
        
        for (i = 0; i < n; ++i) {
            if (nums[i] < 0)
                break;
        }
        
        return i+1;
    }
};

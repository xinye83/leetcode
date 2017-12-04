/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        int ans = nums[0];
        
        while (j-i > 1 && nums[i] > nums[j]) {
            int k = (i+j)/2;
            
            // [i,k] [k+1,j]
            if (nums[i] < nums[k]) {
                ans = min(ans,nums[i]);
                i = k;
            }
            else {
                ans = min(ans,nums[k+1]);
                j = k;
            }
        }
        
        ans = min(ans,nums[i]);
        ans = min(ans,nums[j]);
        
        return ans;
    }
};

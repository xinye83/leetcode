/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        while (j < n) {
            int l = 1;
            
            while (j+l < n && nums[j+l] == nums[j])
                ++l;
            
            nums[i] = nums[j];
            if (l == 1) {
                ++i;
                ++j;
            }
            else {
                nums[i+1] = nums[j];
                i += 2;
                j += l;
            }
        }
        
        return i;
    }
};

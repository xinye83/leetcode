/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans = {nums};
        while (nextPermutation(nums))
            ans.push_back(nums);
        
        return ans;
    }
    
    int nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size()-1; i > 0; --i) {
            if (nums[i] > nums[i-1])
                break;
        }
        
        if (i == 0) {
            return 0;
        }
        
        i--;
        int j = nums.size()-1;
        while (nums[j] <= nums[i])
            j--;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
        
        return 1;
    }
};

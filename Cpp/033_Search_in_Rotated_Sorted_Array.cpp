/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        
        return search2(nums,0,nums.size()-1,0,target);
    }
    
    int search2(vector<int>& nums, int i, int j, int flag, int target) {
        // flag == 1: [i,j] is sorted
        // flag == 0: [i,j] is rotated
        if (nums[i] == target)
            return i;
        if (nums[j] == target)
            return j;
        
        if (j-i < 2)
            return -1;
        
        if (flag) {
            // sorted array
            int k;
            while (j-i > 1) {
                k = (i+j)/2;
                
                if (nums[k] == target)
                    return k;
                
                (nums[k] > target) ? j = k: i = k;
            }
            
            return -1;
        }
        else {
            // rotated array
            int k = (i+j)/2;
            vector<int> v0(2);
            vector<int> v1(2);
            
            // [i,k] & [k+1,j]: one if sorted and one is retated
            if (nums[i] < nums[k]) {
                v1[0] = i;
                v1[1] = k;
                
                v0[0] = k+1;
                v0[1] = j;
            }
            else {
                v0[0] = i;
                v0[1] = k;
                
                v1[0] = k+1;
                v1[1] = j;
            }
            
            if (nums[v1[0]] <= target && nums[v1[1]] >= target)
                return search2(nums,v1[0],v1[1],1,target);
            else
                return search2(nums,v0[0],v0[1],0,target);
        }
        
    }
};

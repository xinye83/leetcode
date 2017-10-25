/*
Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10

Note: Your solution should run in O(log n) time and O(1) space.
*/

int singleNonDuplicate(int* nums, int numsSize) {
    if (numsSize==1) {
        return nums[0];
    }
    
    int i = (numsSize-1)/2;
    if (nums[i-1]!=nums[i] && nums[i+1]!=nums[i]) {
        return nums[i];
    }
    else if (nums[i-1]==nums[i]) {
        return (i%2==0) ?  singleNonDuplicate(nums,i-1) : singleNonDuplicate(nums+i+1,i);
    }
    else {
        return (i%2==0) ? singleNonDuplicate(nums+i+2,i-1) : singleNonDuplicate(nums,i);
    }
}

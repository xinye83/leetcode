/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/

// cmpfunc is rewritten to avoid overflow by computing a-b
int cmpfunc(const void * a, const void * b) {
    if (*(int*)a==*(int*)b) {
        return 0;
    }
    else {
        return (*(int*)a>*(int*)b) ? 1: -1;
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    
    int *singlenum=malloc(2*sizeof(int));
    int c=0;
    int i=0;
    
    *returnSize=2;
    
    while (i<numsSize-1 && c<2) {
        if (nums[i]==nums[i+1]) {
            i+=2;
        }
        else {
            singlenum[c]=nums[i];
            c++;
            i++;
        }
    }
    
    if (i==numsSize-1) {
        singlenum[1]=nums[i];
    }
    
    return singlenum;
}

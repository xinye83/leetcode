// Given an array of integers, find if the array contains any duplicates. 
// Your function should return true if any value appears at least twice in 
// the array, and it should return false if every element is distinct.

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize<=1) {
        return false;
    }
    
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    
    for (int i=0;i<numsSize-1;i++) {
        if (nums[i]==nums[i+1]) {
            return true;
        }
        
        if (i==numsSize-2) {
            return false;
        }
    }
    
    return true;
}

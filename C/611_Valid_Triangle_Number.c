/*
Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].
*/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int binarysearch(int *nums, int numsSize, int j, int k, int val) {
    int x1=j+1;
    int x2=numsSize-1;
    int x0;
    
    if (nums[x1]>=val) {
        return -1;
    }
    
    if (nums[x2]<val) {
        return x2;
    }
    
    if (k>x1) {
        x1=k;
    }
    
    while (x2-x1>1) {
        x0=(x1+x2)/2;
        
        if (nums[x0]>=val) {
            x2=x0;
        }
        else {
            x1=x0;
        }
    }
    
    return x1;
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    
    int k;
    int c=0;
    
    for (int i=0;i<=numsSize-3;i++) {
        k=-1;
        for (int j=i+1;j<=numsSize-2;j++) {
            // binary search for elements smaller than nums[i]+nums[j]
            // from j+1 to numsSize-1
            // but only need to search from k to numsSize-1
            if (k!=numsSize-1) {
                k=binarysearch(nums,numsSize,j,k,nums[i]+nums[j]);
            }
            if (k>0) {
                c+=k-j;
            }
        }
    }
    
    return c;
}

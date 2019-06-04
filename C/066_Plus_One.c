/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digitsSize==1 && digits[0]==0) {
        *returnSize=1;
        digits[0]=1;
        return digits;
    }
        
    int* ans= (int*) malloc((digitsSize+1)*sizeof(int));
    int flag;
    
    if (digits[digitsSize-1]==9) {
        ans[digitsSize]=0;
        flag=1;
    }
    else {
        ans[digitsSize]=digits[digitsSize-1]+1;
        flag=0;
    }
    
    if (digitsSize>1) {
        for (int i=digitsSize-2;i>=0;i--) {
            if (digits[i]==9 && flag==1) {
                ans[i+1]=0;
                flag=1;
            }
            else {
                ans[i+1]=digits[i]+flag;
                flag=0;
            }
        }
    }
    
    if (flag==1) {
        ans[0]=1;
        *returnSize=digitsSize+1;
        return ans;
    }
    else {
        ans[0]=0;
        *returnSize=digitsSize;
        return ans+1;
    }
}

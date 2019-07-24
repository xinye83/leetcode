/*
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]

Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        int index = n-1;
        int i = 0, j = n-1;
        while (i <= j) {
            if (abs(A[i]) >= abs(A[j])) {
                ans[index] = A[i]*A[i];
                i++;
            }
            else {
                ans[index] = A[j]*A[j];
                j--;
            }
            
            index--;
        }
        
        return ans;
    }
};

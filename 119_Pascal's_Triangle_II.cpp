/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        
        if (rowIndex <= 1) {
            return ans;
        }
        
        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                ans[j] += ans[j-1];
            }
        }
        
        return ans;
    }
};

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m)
            return {};
        int n = matrix[0].size();
        if (!n)
            return {};
        
        int k = (m >= n) ? (n-1)/2: (m-1)/2;
        vector<int> ans(m*n);
        int pos = 0;
        
        for (int i = 0; i <= k; i++) {
            // (i,i) > (i,n-1-i) v (m-1-i,n-1-i) < (m-1-i,i) ^ (i+1,i)
            int j = i;
            while (j <= n-1-i)
                ans[pos++] = matrix[i][j++];
            
            j = i+1;
            while (j <= m-1-i)
                ans[pos++] = matrix[j++][n-1-i];
            
            if (i != m-1-i) {
                j = n-2-i;
                while (j >= i)
                    ans[pos++] = matrix[m-1-i][j--];
            }
            
            if (i!= n-1-i) {
                j = m-2-i;
                while (j >= i+1)
                    ans[pos++] = matrix[j--][i];
            }
        }
        
        return ans;
    }
};

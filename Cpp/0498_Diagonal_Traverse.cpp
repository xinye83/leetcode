/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m)
            return {};
        int n = matrix[0].size();
        if (!n)
            return {};
        
        // i+j = k in [0,m+n-2]
        //  i in [max(0,k-n+1), min(m-1,k)]
        vector<int> ans;
        for (int k = 0; k < m+n-1; ++k) {
            int x = max(0,k-n+1);
            int y = min(m-1,k);
            int z = 1;
            
            if (!(k%2)) {
                swap(x,y);
                z = -1;
            }
            
            y += z;
            
            for (int i = x; i != y; i += z)
                ans.push_back(matrix[i][k-i]);
        }
        
        return ans;
    }
};

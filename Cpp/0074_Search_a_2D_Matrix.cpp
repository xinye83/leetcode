/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowsize = matrix.size();
        
        if (rowsize == 0) 
        {
            return 0;
        }
        
        int colsize = matrix[0].size();
        
        if (colsize == 0) 
        {
            return 0;
        }
        
        if (matrix[0][0] == target || matrix[rowsize-1][colsize-1] == target) 
        {
            return 1;
        }
        else if (matrix[0][0] > target || matrix[rowsize-1][colsize-1] < target)
        {
            return 0;
        }

        int x1,x2,x0;
        
        // search for row index
        int row;
        
        if (matrix[rowsize-1][0] == target)
        {
            return 1;
        }
        else if (matrix[rowsize-1][0] < target)
        {
            row = rowsize-1;
        }
        else
        {
            x1 = 0;
            x2 = rowsize-1;

            while (x2-x1 > 1)
            {
                x0 = (x1+x2)/2;

                if (matrix[x0][0] == target) 
                {
                    return 1;
                }
                else if (matrix[x0][0] > target)
                {
                    x2 = x0;
                }
                else
                {
                    x1 = x0;
                }
            }

            row = x1;
        }
        
        if (matrix[row][colsize-1] == target)
        {
            return 1;
        }
        
        // search for col index
        x1 = 0;
        x2 = colsize-1;
        
        while (x2-x1 > 1)
        {
            x0 = (x1+x2)/2;
            
            if (matrix[row][x0] == target) 
            {
                return 1;
            }
            else if (matrix[row][x0] > target)
            {
                x2 = x0;
            }
            else
            {
                x1 = x0;
            }
        }
        
        return 0;
    }
};

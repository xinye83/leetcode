/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) 
        {
            return {};
        }
        else if (n == 1)
        {
            return {{1}};
        }
        
        vector<vector<int>> matrix = generateMatrix(n-2);
        
        int a = 4*n-4;
        
        for (int i = 0; i < n-2; i++)
        {
            for (int j = 0; j < n-2; j++)
            {
                matrix[i][j] += a;
            }
            
            matrix[i].insert(matrix[i].begin(),4*n-4-i);
            matrix[i].push_back(n+i+1);
        }
        
        vector<int> v1;
        vector<int> v2;
        
        for (int i = 0; i < n; i++)
        {
            v1.push_back(i+1);
            v2.push_back(3*n-2-i);
        }
        
        matrix.insert(matrix.begin(),v1);
        matrix.push_back(v2);
        
        return matrix;
    }
};

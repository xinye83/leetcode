/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) {
            return {};
        }
        
        vector<vector<int>> triangle = generate(numRows-1);
        triangle.push_back({});
        
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows-1) {
                triangle[numRows-1].push_back(1);
            }
            else {
                triangle[numRows-1].push_back(triangle[numRows-2][i-1]+triangle[numRows-2][i]);
            }
        }
        
        return triangle;
    }
};

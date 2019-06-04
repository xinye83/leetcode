/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m)
            return 0;
        
        int n = obstacleGrid[0].size();
        if (!n)
            return 0;
        
        if (obstacleGrid[0][0] == 1)
            return 0;
        
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i]) {
                obstacleGrid[0][i] = -1;
                flag = 0;
            }
            else
                obstacleGrid[0][i] = flag;
        }
        
        flag = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0]) {
                obstacleGrid[i][0] = -1;
                flag = 0;
            }
            else
                obstacleGrid[i][0] = flag;
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j])
                    obstacleGrid[i][j] = -1;
                else {
                    if (obstacleGrid[i-1][j] != -1)
                        obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if (obstacleGrid[i][j-1] != -1)
                        obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
            }
        }
        
        return max(obstacleGrid[m-1][n-1],0);
    }
};

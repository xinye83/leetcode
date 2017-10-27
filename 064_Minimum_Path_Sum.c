/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
 
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
*/

int min(int a, int b) {
    return (a<=b) ? (a): (b);
}

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    for (int i=0;i<gridRowSize;i++) {
        for (int j=0;j<gridColSize;j++) {
            if (!i && j) {
                grid[i][j]+=grid[i][j-1];
            }
            else if (i && !j) {
                grid[i][j]+=grid[i-1][j];
            }
            else if (i && j) {
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
    }
    
    return grid[gridRowSize-1][gridColSize-1];
}

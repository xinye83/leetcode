/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        #include <stack>
        
        int row = grid.size();
        if (!row)
            return 0;
        
        int col = grid[0].size();
        if (!col)
            return 0;
        
        int i,j,c;
        c = 0;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    c++;
                    
                    stack<vector<int>> st;
                    vector<int> pt = {i,j};
                    st.push(pt);
                    
                    while (!st.empty()) {
                        pt = st.top();
                        st.pop();
                        
                        grid[pt[0]][pt[1]] = '0';
                        
                        if (pt[0] != 0 && grid[pt[0]-1][pt[1]] == '1')
                            st.push({pt[0]-1,pt[1]});
                        if (pt[0] != row-1 && grid[pt[0]+1][pt[1]] == '1')
                            st.push({pt[0]+1,pt[1]});
                        if (pt[1] != 0 && grid[pt[0]][pt[1]-1] == '1')
                            st.push({pt[0],pt[1]-1});
                        if (pt[1] != col-1 && grid[pt[0]][pt[1]+1] == '1')
                            st.push({pt[0],pt[1]+1});
                    }
                } 
            }
        }
        
        return c;
    }
};

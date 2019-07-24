/*
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5

Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3

Example 3:

Input: stones = [[0,0]]
Output: 0
 

Note:

1 <= stones.length <= 1000
0 <= stones[i][j] < 10000
*/

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }
        
        vector<int> visit(n, 0);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visit[i] == 0) {
                int sz = 0;
                stack<int> group;
                
                visit[i] = 1;
                group.push(i);              
                while (!group.empty()) {
                    int l = group.top();
                    group.pop();
                    
                    sz++;
                    
                    for (int j = 0; j < n; ++j) {
                        if (graph[l][j] == 1 && visit[j] == 0) {
                            group.push(j);
                            visit[j] = 1;
                        }
                    }
                }
                
                ans += sz-1;
            }
        }
        
        return ans;
    }
};

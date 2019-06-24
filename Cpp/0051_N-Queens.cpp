/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string row;
        for (int i = 0; i < n; ++i)
            row += '.';
        for (int i = 0; i < n; ++i)
            board.push_back(row);
        
        queue<pair<int, vector<string>>> q;
        q.push(make_pair(0, board));
        
        vector<vector<string>> ans;
        while (!q.empty()) {
            if (q.front().first == n) {
                ans.push_back(q.front().second);
                q.pop();
            }
            else {
                int r = q.front().first;
                
                for (int i = 0; i < n; ++i) {
                    // check if temp[r][i] can be a queen
                    vector<string> temp = q.front().second;
                    int flag = 1;
                    
                    // check column
                    for (int j = 0; j < r; ++j) {
                        if (temp[j][i] == 'Q') {
                            flag = 0;
                            break;
                        }
                    }
                    
                    if (flag == 0)
                        continue;
                    
                    // check diagonal
                    int rr = r-1, ii = i+1;
                    while (rr >= 0 && ii < n) {
                        if (temp[rr][ii] == 'Q') {
                            flag = 0;
                            break;
                        }
                        
                        rr--;
                        ii++;
                    }
                    
                    if (flag == 0)
                        continue;
                    
                    // check anti-diagonal
                    rr = r-1, ii = i-1;
                    while (rr >= 0 && ii >= 0) {
                        if (temp[rr][ii] == 'Q') {
                            flag = 0;
                            break;
                        }
                        
                        rr--;
                        ii--;
                    }
                    
                    if (flag == 0)
                        continue;
                    
                    temp[r][i] = 'Q';
                    
                    q.push(make_pair(r+1, temp));
                }
                
                q.pop();
            }
        }
        
        return ans;
    }
};

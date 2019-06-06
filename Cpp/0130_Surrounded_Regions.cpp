/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:
    vector<int> boundary(int row, int col, int i) {
        // return the i-th boundary point coordinate
        // 1 <= i <= 2*row+2*col-4
        if (i <= col) {
            return {0, i-1};
        }
        else if (i <= row+col-1) {
            return {i-col, col-1};
        }
        else if (i <= row+2*col-2) {
            return {row-1, row+2*col-2-i};
        }
        else {
            return {2*row+2*col-3-i, 0};
        }
    }
    
    void solve(vector<vector<char>>& board) {
        #include <stack>
        
        int row = board.size();
        if (row <= 2) {
            return;
        }
        
        int col = board[0].size();
        if (col <= 2) {
            return;
        }
        
        int i = 0;
        vector<int> pt;
        stack<vector<int>> st;
        
        while (!st.empty() || i < 2*row+2*col-4) {
            if (st.empty()) {
                i++;
                pt = boundary(row,col,i);
                
                if (board[pt[0]][pt[1]] == 'O') {
                    st.push(pt);
                }
            }
            else {
                pt = st.top();
                st.pop();
                
                board[pt[0]][pt[1]] = 'P';
                
                if (pt[0] != 0 && board[pt[0]-1][pt[1]] == 'O') {
                    st.push({pt[0]-1,pt[1]});
                }
                if (pt[0] != row-1 && board[pt[0]+1][pt[1]] == 'O') {
                    st.push({pt[0]+1,pt[1]});
                }
                if (pt[1] != 0 && board[pt[0]][pt[1]-1] == 'O') {
                    st.push({pt[0],pt[1]-1});
                }
                if (pt[1] != col-1 && board[pt[0]][pt[1]+1] == 'O') {
                    st.push({pt[0],pt[1]+1});
                }
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};

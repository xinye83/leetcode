/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        /*  2-10 means a dead cell with 0-8 live neigbors
           11-19 means a live cell with 0-8 live neigbors
         */
        int m = board.size();
        int n = board[0].size();
        
        // count neigbors
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = 0;
                
                for (int x = -1; x < 2; ++x) {
                    for (int y = -1; y < 2; ++y) {
                        if (i+x >= 0 && i+x < m && j+y >= 0 && j+y < n && (x || y))
                            c += (board[i+x][j+y] == 1 || board[i+x][j+y] > 10);
                    }
                }
                
                board[i][j] *= 9;
                board[i][j] += 2+c;
            }
        }
        
        // next generation
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 5 || board[i][j] == 13 || board[i][j] == 14)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};

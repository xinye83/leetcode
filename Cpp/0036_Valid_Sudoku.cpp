/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(9,0));
        vector<vector<int>> col(row);
        vector<vector<int>> blk(row);
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (row[i][board[i][j]-'1'])
                        return 0;
                    else
                        row[i][board[i][j]-'1'] = 1;
                    
                    if (col[j][board[i][j]-'1'])
                        return 0;
                    else
                        col[j][board[i][j]-'1'] = 1;
                    
                    if (blk[(i/3)*3+j/3][board[i][j]-'1'])
                        return 0;
                    else
                        blk[(i/3)*3+j/3][board[i][j]-'1'] = 1;
                }
            }
        }
        
        return 1;
    }
};

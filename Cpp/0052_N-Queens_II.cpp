/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[i] = i;
        }
        
        int ans = 0;
        do {
            if (isValidNQueens(pos) == true) {
                ans++;
            } 
        } while (next_permutation(pos.begin(), pos.end()) == true);
               
        return ans;
    }
               
    bool isValidNQueens(vector<int> pos) {
        int n = pos.size();
        
        // check diagonal
        unordered_set<int> diag;
        for (int i = 0; i < n; ++i) {
            if (diag.count(pos[i]-i) == 1) {
                return false;
            }
            
            diag.emplace(pos[i]-i);
        }
        
        // check antidiagonal
        unordered_set<int> antidiag;
        for (int i = 0; i < n; ++i) {
            if (antidiag.count(pos[i]+i) == 1) {
                return false;
            }
            
            antidiag.emplace(pos[i]+i);
        }
        
        return true;
    }
};

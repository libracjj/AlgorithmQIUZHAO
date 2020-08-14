/*
https://leetcode-cn.com/problems/sudoku-solver/
37. 解数独
*/
class Solution {
public:
    bool solve(vector<vector<char>>& board, int r, int c) {
        if (r > 8) return true;
        if (board[r][c] != '.') return solve(board, r+(c+1)/9, (c+1)%9);
        else {
            for (int i = 1; i <= 9; i++) {
                if (row[r][i] == 1 || col[c][i] == 1 || box[c/3 + r/3*3][i] == 1) continue;
                board[r][c] = i + '0';
                row[r][i] = 1, col[c][i] = 1, box[c/3 + r/3*3][i] = 1;
                if (solve(board, r+(c+1)/9, (c+1)%9)) return true;
                board[r][c] = '.';
                row[r][i] = 0, col[c][i] = 0, box[c/3 + r/3*3][i] = 0;
            }
        }
        return false;
    }
    int row[9][10], col[9][10], box[9][10];
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int cur = board[i][j] - '0';
                    row[i][cur] = 1;
                    col[j][cur] = 1;
                    box[j/3 + i/3*3][cur] = 1;
                }
            }
        }
        solve(board, 0, 0);
    }
};
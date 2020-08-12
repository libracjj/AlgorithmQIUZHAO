/*
https://leetcode-cn.com/problems/valid-sudoku/
36. 有效的数独
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0}, col[9][10] = {0}, box[9][10] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                if (row[i][cur]) return false;
                if (col[j][cur]) return false;
                if (box[j/3 + (i/3)*3][cur]) return false;

                row[i][cur] = 1;
                col[j][cur] = 1;
                box[j/3 + (i/3)*3][cur] = 1;
            }
        }
        return true;
    }
};
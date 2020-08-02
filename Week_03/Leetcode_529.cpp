/*
https://leetcode-cn.com/problems/minesweeper/
529. 扫雷游戏
1.DFS
*/
class Solution {
public:
    int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row  = click[0], col = click[1];
        int m = board.size(), n = board[0].size();
        if (board[row][col] == 'M' ||
            board[row][col] == 'X') {
                board[row][col] = 'X';
                return board;
        }
        int num = 0;
        for (auto dir : dirs) {
            int newrow = row + dir[0];
            int newcol = col + dir[1];
            if (newrow >= 0 && newcol >= 0 && newrow < m && newcol < n &&
                board[newrow][newcol] == 'M')
                num++;
        }
        if (num != 0) {
            board[row][col] = char(num + '0');
        }
        else {
            board[row][col] = 'B';
            for (auto dir : dirs) {
                int newrow = row + dir[0];
                int newcol = col + dir[1];
                if (newrow >= 0 && newcol >= 0 && newrow < m && newcol < n && 
					board[newrow][newcol] == 'E') {
                    vector<int> t({newrow, newcol});
                    updateBoard(board, t);
                }
            }
        }
        return board;        
    }
};
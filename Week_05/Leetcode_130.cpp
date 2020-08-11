/*
https://leetcode-cn.com/problems/surrounded-regions/
130. 被围绕的区域
*/
class Solution {
public:
    int m, n;//m行 n列
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0 ,1}};
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x >= m || x < 0 || y >= n || y < 0 || board[x][y] != 'O')
            return;
        board[x][y] = 'A';
        for (auto dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            dfs(board, nx, ny);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0)
            return;
        n = board[0].size();
        for (int i = 0; i < m ; i++) {//第1列和最后一列
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++) {//第一行和最后一行，从第2列到倒数第2列即可
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};
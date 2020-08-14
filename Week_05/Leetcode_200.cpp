/*
https://leetcode-cn.com/problems/number-of-islands/
200. 岛屿数量
*/
class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        if (row >= m || col >= n || row < 0 || col < 0 || grid[row][col] != '1')
            return;
        grid[row][col] = '0';
        
        for (auto dir : dirs) {
            int newrow = row + dir[0], newcol = col + dir[1];
            dfs(grid, newrow, newcol);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
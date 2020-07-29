/*
200. 岛屿数量
https://leetcode-cn.com/problems/number-of-islands/
*/

class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (j < 0 || i < 0 || j >= grid[0].size() || i >= grid.size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        return cnt;
    }
};
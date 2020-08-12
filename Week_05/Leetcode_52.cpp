/*
https://leetcode-cn.com/problems/n-queens-ii/
52. N皇后 II
*/
class Solution {
public:
    vector<int> path;
    int size, ans = 0;
    void dfs(int depth){//行
        if (depth == size) {
            ans++;
            return;
        }
        for (int col = 0; col < size; col++) {
            if (check(depth, col)) {
                path.push_back(col);
                dfs(depth + 1);
                path.pop_back();
            }
        }
    }
    bool check(int row, int col) {
        for(int i = 0; i < path.size(); i++) {
            if (path[i] == col || path[i] + i == row + col || path[i] - i == col - row) {
                return false;
            }
        }
        return true;
    }
    int totalNQueens(int n) {
        size = n;
        dfs(0);
        return ans;
    }
};
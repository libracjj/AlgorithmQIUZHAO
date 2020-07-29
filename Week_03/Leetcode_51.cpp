/*
https://leetcode-cn.com/problems/n-queens/
51. N皇后
参考：https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.
Python: https://leetcode.com/problems/n-queens/discuss/19810/Fast-short-and-easy-to-understand-python-solution-11-lines-76ms
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));//初始化一个答案
        solve(res, nQueens, 0, n);

        return res;
    }
private:
    void solve(vector< vector<string> > &res, vector<string> &nQueens, int row, int n) {
        if (row == n) {
            res.push_back(nQueens);
            return ;
        }
        for (int col = 0; col < n; col++) {
            if (isV(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solve(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    bool isV(vector<string> &nQueens, int row, int col, int n) {
        for (int i = 0; i != row; i++) {
            if (nQueens[i][col] == 'Q') 
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (nQueens[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (nQueens[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
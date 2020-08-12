/*
https://leetcode-cn.com/problems/n-queens/
51. N皇后
*/
//回溯 + 减枝
class Solution {
public:
    int size;
    vector<int> path;//存皇后列的位置，path[i]表示 i行 某一列
    vector< vector<string> > res;
    void dfs(int depth) {
        if (depth == size) {
            string str(size, '.');//全为'.'
            vector<string> strVec(size, str);
            for (int i = 0; i < size; i++)
                strVec[i][path[i]] = 'Q';
            res.push_back(strVec);
            return;
        }
        for (int col = 0; col < size; col++) {
            if (check(depth, col)) {//depth行
                path.push_back(col);
                dfs(depth + 1);
                path.pop_back();
            }
        }
    }
    bool check(int row, int col) {
        for (int i = 0; i < path.size(); i++) {
		//按行放，行不会冲突；检查列是否冲突 主副对角线冲突
            if (path[i] == col || path[i] - i == col - row || path[i] + i == col + row)
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        dfs(0);
        return res;
    }
};
//位运算
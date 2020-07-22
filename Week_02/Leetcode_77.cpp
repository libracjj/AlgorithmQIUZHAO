/*
77. 组合
https://leetcode-cn.com/problems/combinations/
*/

class Solution {
public:
    void dfs(vector< vector<int> > &results, vector<int> &res, int n, int k, int start) {
        if (k == 0) {
            results.push_back(res);
            return;
        }
        for (int i = start; i <= n; i++) {
            res.push_back(i);
            dfs(results, res, n, k-1, i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector< vector<int> > results;
        vector<int> res;
        dfs(results, res, n, k, 1);
        return results;
    }
};
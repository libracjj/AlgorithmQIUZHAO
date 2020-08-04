/*
https://leetcode-cn.com/problems/maximal-square/
221. 最大正方形
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) 
            return 0;
        int Max = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector< vector<int> > dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    }
                    Max = max(Max, dp[i][j]);
                }
            }
        }
        return Max * Max;
    }
};
/*
https://leetcode-cn.com/problems/burst-balloons/
312. 戳气球
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int> > dp(n+2, vector<int> (n+2, 0));
        vector<int> val(n+2);
        val[0] = val[n+1] = 1;
        for (int i = 1; i <= n; i++)
            val[i] = nums[i-1];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j],
                    (dp[i][k] + dp[k][j] + val[i] * val[k] * val[j]));
                }
            }
        }
        return dp[0][n+1];
    }
};
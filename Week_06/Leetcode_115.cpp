/*
https://leetcode-cn.com/problems/distinct-subsequences/
115. 不同的子序列
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector< vector<long> > dp(t.size()+1, vector<long> (s.size()+1));
        for (int j = 0; j < s.size(); j++) dp[0][j] = 1;

        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                dp[i][j] = dp[i][j-1];
                if (t[i-1] == s[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[t.size()][s.size()];
    }
};
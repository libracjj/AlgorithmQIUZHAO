/*
https://leetcode-cn.com/problems/wildcard-matching/
44. 通配符匹配
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector< vector<bool> > dp(p.size()+1, vector<bool>(s.size()+1));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++) {
            if (p[i-1] != '*') {
                break;
            }
            dp[i][0] = true;
        }
        for (int i = 1; i <= p.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if (p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
            }
        }
        return dp[p.size()][s.size()];
    }
};
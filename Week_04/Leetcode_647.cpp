/*
https://leetcode-cn.com/problems/palindromic-substrings/
647. 回文子串

*/
class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size(), ans = 0;
        vector< vector<bool> > dp(n, vector<bool> (n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i+1][j-1]);
                if (dp[i][j]) ans++;
            }
        }
        return ans;
    }
};
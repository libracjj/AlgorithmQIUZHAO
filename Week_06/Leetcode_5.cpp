/*
https://leetcode-cn.com/problems/longest-palindromic-substring/
5. 最长回文子串
*/
//从中心向两边扩展
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int ans = 1;
        string res = s.substr(0, 1);
        for (int i = 0; i < s.size(); i++) {
            string odd = Expand(s, i, i);
            string even = Expand(s, i, i + 1);
            string Max = odd.size() > even.size() ? odd : even;
            if (Max.size() > ans) {
                ans = Max.size();
                res = Max;
            }
        }
        return res;
    }
    string Expand(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            L--, R++;
        }
        return s.substr(L + 1, R - L - 1);
    }
};
//DP
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int n = s.size();
        vector< vector<bool> > dp(n, vector<bool>(n));
        int start, ans = 1;
        for (int j = 0; j < s.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2 || dp[i+1][j-1])
                        dp[i][j] = true;
                    if (dp[i][j]) {
                        if (ans < j - i + 1) {
                            ans = j - i + 1;
                            start = i;
                        }
                    }
                }        
            }
        }
        return s.substr(start, ans);
    }
};
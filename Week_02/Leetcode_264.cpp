/*
https://leetcode-cn.com/problems/ugly-number-ii/
264. 丑数 II
*/
//动态规划
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            int a2 = dp[a] * 2, b3 = dp[b] * 3, c5 = dp[c] * 5;
            dp[i] = min(min(a2, b3), c5);
            //去除重复元素
            if (dp[i] == a2) a++;
            if (dp[i] == b3) b++;
            if (dp[i] == c5) c++;
        }
        return dp[n-1];
    }
};
/*
https://leetcode-cn.com/problems/longest-increasing-subsequence/
300. 最长上升子序列
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);        
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
/*
https://leetcode-cn.com/problems/jump-game-ii/
45. 跳跃游戏 II
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size() - 1, end = 0, step = 0;
        for (int i = 0; i < n ; i++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    step++;
                }
            }
        }
        return step;
    }
};
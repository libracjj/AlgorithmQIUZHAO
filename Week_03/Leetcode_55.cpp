/*
https://leetcode-cn.com/problems/jump-game/
55. 跳跃游戏
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        int end = nums.size() - 1;
        for (int i = end; i >= 0; i--) {
            if (nums[i] + i >= end) {
                end = i;
            }
        }
        return end == 0;
    }
};
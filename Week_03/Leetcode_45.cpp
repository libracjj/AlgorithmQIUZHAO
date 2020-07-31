/*
https://leetcode-cn.com/problems/jump-game-ii/
45. 跳跃游戏 II
在遍历数组时，我们不访问最后一个元素，
这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，
否则就无法跳到最后一个位置了。
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
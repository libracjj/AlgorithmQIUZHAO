/*
169. 多数元素
https://leetcode-cn.com/problems/majority-element/
*/
//计数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int F = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == F)
                cnt++;
            else {
                cnt--;
                if (cnt == 0) {
                    F = nums[i + 1];
                }
            }
        }
        return F;
    }
};
/*
分治法
*/
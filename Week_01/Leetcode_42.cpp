//42. 接雨水
//https://leetcode-cn.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_l = 0, max_r = 0, ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                max_l <= height[left] ? max_l = height[left] : ans += max_l - height[left];
                left++;
            }
            else {
                max_r <= height[right] ? max_r = height[right] : ans += max_r - height[right];
                right--;
            }
        }
        return ans;        
    }
};
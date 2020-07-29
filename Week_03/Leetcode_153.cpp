/*
153. 寻找旋转排序数组中的最小值
https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
使用二分
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (right > left) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
/*
//双指针
class Solution {
public:
    int findMin(vector<int>& nums) {
        int j = 0, res;
        res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] <= nums[i]) {
                j++;
            }
            else {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
*/
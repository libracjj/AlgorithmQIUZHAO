//26. 删除排序数组中的重复项
//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        if (nums.size() == 0) return 0;//检查数组是否为空
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};
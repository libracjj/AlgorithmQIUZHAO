//283. 移动零
//https://leetcode-cn.com/problems/move-zeroes/

//双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[j] = nums[i];
                if(i != j){
                    nums[i] = 0;//相当于位置交换
                }
                j++;//左加1
            }
        }
    }
};
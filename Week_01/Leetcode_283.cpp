//283. �ƶ���
//https://leetcode-cn.com/problems/move-zeroes/

//˫ָ��
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[j] = nums[i];
                if(i != j){
                    nums[i] = 0;//�൱��λ�ý���
                }
                j++;//���1
            }
        }
    }
};
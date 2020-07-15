//https://leetcode-cn.com/problems/rotate-array/
//189. 旋转数组
//翻转3次，reverse的头文件为 #include<algorithm>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin() + n - k, nums.begin() + n);  
        reverse(nums.begin(), nums.begin() + n - k);    

        reverse(nums.begin(), nums.begin() + n);
    }
};
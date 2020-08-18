/*
https://leetcode-cn.com/problems/reverse-pairs/
493. 翻转对
*/
class Solution {
public:
    int cnt;
    void MergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = (left + right) >> 1;
        MergeSort(nums, left, mid);
        MergeSort(nums, mid + 1, right);
        Merge(nums, left, mid, right);
    }
    void Merge(vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0;
        vector<int> temp(right - left + 1);
        while (i <= mid && j <= right) {
            if ((long) nums[i] > (long) nums[j] * 2) {//左边i到mid都符合 统计个数 并看下一个j
                cnt += mid - i + 1;
                j++;
            }
            else {
                i++;
            }
        } 
        i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];
        for (i = left, k = 0; i <= right; ) nums[i++] = temp[k++];
    }
    int reversePairs(vector<int>& nums) {
        if (!nums.size()) return 0;
        cnt = 0;
        MergeSort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
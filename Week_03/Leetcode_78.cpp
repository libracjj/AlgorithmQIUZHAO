/*
78. 子集
https://leetcode-cn.com/problems/subsets/
*/
class Solution {
public:
    vector< vector<int> > results;
    void helper(vector<int> &res, vector<int>& nums, int st) {
        results.push_back(res);
        for (int i = st; i < nums.size(); i++) {
            res.push_back(nums[i]);
            helper(res, nums, i + 1);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        
        helper(res, nums, 0);
        return results;
    }
};
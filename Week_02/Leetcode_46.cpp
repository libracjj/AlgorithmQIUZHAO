/*
46. 全排列
https://leetcode-cn.com/problems/permutations/
*/
class Solution {
public:
    void helper(vector< vector<int> > &results, vector<int> &res,vector<int> &nums, vector<bool> &visited) {
        if (res.size() == nums.size()) {
            results.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                res.push_back(nums[i]);
                visited[i] = true;
                helper(results, res, nums, visited);
                res.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector< vector<int> > results;
        vector<int> res;
        vector<bool> visited(n, false);
        helper(results, res, nums, visited);
        return results;
    }
};
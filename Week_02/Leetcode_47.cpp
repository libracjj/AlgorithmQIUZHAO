/*
47. 全排列 II
https://leetcode-cn.com/problems/permutations-ii/
题解：https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines

*/
class Solution {
public:
    void helper(vector< vector<int> > &paths, vector<int> &path,vector<bool> &visited, vector<int> &nums) {
        if (path.size() == nums.size()) {
            paths.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1]) continue;//去重
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(nums[i]);
                
                helper(paths, path, visited, nums);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector< vector<int> > paths;
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());//排序
        helper(paths, path, visited, nums);
        return paths;
    }
};
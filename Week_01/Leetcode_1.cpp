//1. 两数之和
//https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if(hash.count(t)){
                res.push_back(hash[t]), res.push_back(i);
                break;
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
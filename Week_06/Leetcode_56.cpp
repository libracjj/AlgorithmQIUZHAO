/*
https://leetcode-cn.com/problems/merge-intervals/
56. 合并区间
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector< vector<int> > res;
        for (int i = 0; i < intervals.size(); ) {
            int t = intervals[i][1];//右
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            res.push_back({intervals[i][0], t});
            i = j;
        }
        return res;
    }
};
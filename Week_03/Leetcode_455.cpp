/*
https://leetcode-cn.com/problems/assign-cookies/
455. 分发饼干
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0, j = 0;
        for (int i = 0; i < s.size() && j < g.size(); i++) {
            if(g[j] <= s[i]) {
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};
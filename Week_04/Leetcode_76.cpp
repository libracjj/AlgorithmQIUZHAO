/*
https://leetcode-cn.com/problems/minimum-window-substring/
76. 最小覆盖子串
*/

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (auto c : t) map[c]++;
        int left = 0, right = 0, d = INT_MAX, head = 0;
        int counter = t.size();
        while (right < s.size()) {
            if (map[s[right++]]-- > 0) counter--;
            while (counter == 0) {
                if (right - left < d) d = right - (head = left);
                if (map[s[left++]]++ == 0) counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
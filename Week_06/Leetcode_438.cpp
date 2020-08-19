/*
https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
438. 找到字符串中所有字母异位词
*/
//滑动窗口
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int map[27] = {0};
        for (auto c : p) map[c - 'a']++;
        int left = 0, right = 0, counter = p.size();
        vector<int> res;
        while (right < s.size()) {
            if (map[s[right++] - 'a']-- > 0) counter--;
            while (counter == 0) {
                if (right - left == p.size()) res.push_back(left);
                if (map[s[left++] - 'a']++ == 0) counter++;
            }
        }
        return res;
    }
};
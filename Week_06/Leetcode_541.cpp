/*
https://leetcode-cn.com/problems/reverse-string-ii/
541. 反转字符串 II
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()) {
            if (i + k > s.size()) reverse(s.begin() + i, s.end());
            else reverse(s.begin() + i, s.begin() + i + k);
            i += 2*k;
        }
        return s;
    }
};
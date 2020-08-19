/*
https://leetcode-cn.com/problems/valid-palindrome-ii/
680. 验证回文字符串 Ⅱ
*/
class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 0, s.size() - 1, false);
    }
    bool valid(string s, int i, int j, bool isDeep) {
        while (i < j) {
            char a = s[i], b = s[j];
            if (a != b) {
                if(isDeep) return false;
                return valid(s, i, j - 1, true) || valid(s, i + 1, j, true);
            }
            i++, j--;
        }
        return true;
    }
};
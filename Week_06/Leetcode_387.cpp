/*
https://leetcode-cn.com/problems/first-unique-character-in-a-string/
387. 字符串中的第一个唯一字符
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
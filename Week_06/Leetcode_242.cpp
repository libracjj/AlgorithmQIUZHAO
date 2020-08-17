/*
https://leetcode-cn.com/problems/valid-anagram/
242. 有效的字母异位词
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int map[27] = {0};
        for (auto c : s) map[c - 'a']++;
        for (auto c : t) map[c - 'a']--;
        for(int i = 0; i < 26; i++) {
            if (map[i] != 0)
                return false;
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
*/
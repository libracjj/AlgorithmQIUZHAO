//242. 有效的字母异位词
//https://leetcode-cn.com/problems/valid-anagram/
//说明中 提到 字符串只包含小写字母
class Solution {
public:
    bool isAnagram(string s, string t) {
        int r[27] = {0};
        for (char& a:s) {
            r[a - 'a']++;
        }
        for (char& a:t) {
            r[a - 'a']--;
        }
        for (int& i:r) {
            if (i != 0) 
                return false;
        }
        return true;
    }
};
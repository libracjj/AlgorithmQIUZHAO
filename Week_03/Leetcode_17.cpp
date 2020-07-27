/*
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
17. 电话号码的字母组合
*/
class Solution {
public:
    const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string s, string &digits, int n, vector<string> &res) {
        if (n == digits.size()) {
            res.push_back(s);
            return;
        }
        string letters = v[digits[n] - '0'];
        for (int i = 0; i < letters.length(); i++) {
            helper(s + letters[i], digits, n + 1, res);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) {
            return res;
        }
        helper("", digits, 0, res);
        return res;
    }
};

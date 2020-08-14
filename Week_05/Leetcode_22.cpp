/*
https://leetcode-cn.com/problems/generate-parentheses/
22. 括号生成
*/
class Solution {
public:
    void _generator(vector<string> &res, int left, int right, string s) {
        if (right == 0) {
            res.push_back(s);
            return;
        }
        if (left > 0) {
            _generator(res, left - 1, right, s + "(");
        }
        if(right > left) {
            _generator(res, left, right - 1, s + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        _generator(res, n, n, "");
        return res;
    }
};
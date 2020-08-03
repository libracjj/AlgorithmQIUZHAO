/*
https://leetcode-cn.com/problems/longest-valid-parentheses/
32. 最长有效括号
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans = 0;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stk.push(i);
            else {
                stk.pop();
                if (stk.empty())
                    stk.push(i);//最后一个没有被匹配的右括号的下标
                else
                    ans = max(ans, i - stk.top());
            }
        }
        return ans;
    }
};
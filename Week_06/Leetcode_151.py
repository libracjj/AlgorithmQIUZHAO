'''
https://leetcode-cn.com/problems/reverse-words-in-a-string/
151. 翻转字符串里的单词
'''
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join(s.split()[::-1])
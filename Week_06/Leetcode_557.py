'''
https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
557. 反转字符串中的单词 III
'''
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(i[::-1] for i in s.split())
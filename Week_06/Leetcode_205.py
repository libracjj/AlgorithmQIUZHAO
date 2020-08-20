'''
https://leetcode-cn.com/problems/isomorphic-strings/
205. 同构字符串
'''
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dic = {}
        for i in range(len(s)):
            if s[i] in dic:
                if dic[s[i]] == t[i]: continue
                return False
            else:
                if t[i] in dic.values():#如果(s[i], t[i])已经存在于字典中
                    return False;
                dic[s[i]] = t[i]
        return True
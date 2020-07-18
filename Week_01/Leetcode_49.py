#49. 字母异位词分组
#https://leetcode-cn.com/problems/group-anagrams/
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        dic = {}
        #必须用tuple
        for s in strs:
            dic[tuple(sorted(s))] = dic.get(tuple(sorted(s)), []) + [s]

        return dic.values();
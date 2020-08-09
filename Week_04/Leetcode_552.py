'''
552. 学生出勤记录 II
https://leetcode-cn.com/problems/student-attendance-record-ii/
'''
class Solution(object):
    def checkRecord(self, n):
        """
        :type n: int
        :rtype: int
        """
		#n 是正整数
        M = 10**9 + 7#取模
		#n 为1时各种情况的值
        P, AP, L, LL, AL, ALL, A = 1, 0, 1, 0, 0, 0, 1
		'''
		P:序列中无A，最新1个记录不是L；AP:序列中有过A，最新1个记录不是L
		L:没有A，最新1个记录L；LL：最新2个记录是LL
		ALL：有过A，最新2个记录是LL； A最新一个记录是A
		'''
        for i in range(2, n+1):
            P, AP, L, LL, AL, ALL, A = (
                (P + L + LL) % M,
                (AP + AL + ALL + A) % M,
                P,
                L,
                (AP + A) % M,
                AL,
                (P + L + LL) % M,
            )
        return (P + AP + L + LL + AL + ALL + A) % M
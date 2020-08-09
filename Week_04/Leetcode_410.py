'''
https://leetcode-cn.com/problems/split-array-largest-sum/
410. 分割数组的最大值
'''
class Solution(object):
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        if len(nums) == m:
            return max(nums)
        lo, hi = max(nums), sum(nums)
        while(lo < hi):
            mid = (lo + hi) // 2
            temp, cnt = 0, 1
            for num in nums:
                temp += num
                #当前子数组和已超过允许最大值，当前元素放在下一个子数组中
                if temp > mid:
                    temp = num
                    cnt += 1
            if cnt > m:#分出的子数组比要求多
                lo = mid + 1
            elif cnt <= m:
                hi = mid
        return lo
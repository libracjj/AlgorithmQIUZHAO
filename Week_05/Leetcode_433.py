'''
https://leetcode-cn.com/problems/minimum-genetic-mutation/
433. 最小基因变化
'''
class Solution(object):
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        front = {start}
        back = {end}
        bank = set(bank)
        if end not in bank: return -1
        step = 0
        while front:
            step += 1
            tempset = set()
            for G in front:#每一个序列
                for i in range(len(G)):#序列长度
                    for k in "ACGT":
                        new_G = G[:i] + k + G[i+1:]
                        if new_G in back:
                            return step
                        if new_G in bank:
                            print(new_G)
                            tempset.add(new_G)
                            bank.remove(new_G)
            front = tempset
            if len(front) > len(back):
                front, back = back, front
        return -1
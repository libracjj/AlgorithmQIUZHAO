'''
https://leetcode-cn.com/problems/word-ladder/
127. 单词接龙
'''
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        if endWord not in wordList: return 0
        wordList = set(wordList)
        front = {beginWord}#向后扩散
        back = {endWord}#向前扩散
        step = 1
        while front:
            step += 1
            tempSet = set()#临时集合
            for word in front:
                for i in range(len(word)):
                    for c in string.lowercase:
                        next_word = word[:i] + c + word[i+1:]#并不改变word本身
                        if next_word in back:#相遇时返回
                            return step
                        if next_word in wordList:
                            tempSet.add(next_word)#加入新的节点
                            wordList.remove(next_word)#同时从字典中删除
            front = tempSet#临时集合 赋给front
            if len(front) > len(back):#比较哪个集合扩散得到的节点少，从少的继续扩散
                front, back = back, front
        return 0

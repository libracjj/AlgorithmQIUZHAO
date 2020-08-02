'''
https://leetcode-cn.com/problems/word-ladder-ii/
126. 单词接龙 II
注意代码中的"," !!
https://leetcode.com/problems/word-ladder-ii/discuss/768362/Simple-Python-BFS-solution-with-20-lines-of-code-and-explanation-beats-80!
'''
class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        adjList = defaultdict(list)
        #字典构造邻接表
        for word in wordList:
            for i in range(len(word)):
                _key = word[:i] + '*' + word[i+1:]
                adjList[_key] += word,
        q = deque([(beginWord, [beginWord])])#q (word, 已经访问过的单词)
        res = []
        visited = {beginWord: 1}#访问词典 访问时间
        while len(q):
            word, _list = q.popleft()#弹出
            dist = len(_list)#到beginWord的距离
            if word == endWord:
                res += _list,#加入结果集
                continue
            for i in range(len(word)):
                _key = word[:i] + '*' + word[i+1:]
                for child in adjList[_key]:
                    if child not in visited or dist <= visited[child]:#未访问过 或 到beginWord的距离 <= 访问该词的时间
                        q += (child, _list[:]+[child]), #入队
                        visited[child] = dist
        return res
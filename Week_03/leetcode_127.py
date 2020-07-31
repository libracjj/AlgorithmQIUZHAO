class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordList = set(wordList)
        q = collections.deque([(beginWord, 1)])
        while q:
            word, length = q.popleft()
            if word == endWord:
                return length
            for i in range(len(word)):
                for c in string.lowercase:
                    next_word = word[:i] + c + word[i + 1:]
                    if next_word in wordList:
                        #print(next_word)
                        q.append((next_word, length + 1))
                        wordList.remove(next_word)
        return 0
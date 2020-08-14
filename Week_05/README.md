# 简 单

[70：爬楼梯](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_70.cpp)                    已完成     
[191：位 1 的个数](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_191.cpp)                    已完成   
[231：2 的幂](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_231.cpp)                    已完成   
[190：颠倒二进制位](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_190.cpp)                    已完成   

# 中 等

[208：实现 Trie (前缀树)](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_208.py)                    已完成   
[547：朋友圈](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_547.cpp)                    已完成   
[200：岛屿数量](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_200.cpp)                    已完成  
[130：被围绕的区域](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_130.cpp)                     已完成   
[36：有效的数独](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_36.cpp)                     已完成   
[22：括号生成](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_22.cpp)                     已完成  
[127：单词接龙](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_127.py)  **双向BFS**                       已完成   
[433：最小基因变化](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_433.py)  **双向BFS**                     已完成   
[338：比特位计数](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_338.cpp)                    已完成      

# 困 难

[212：单词搜索 II ](https://leetcode-cn.com/problems/word-search-ii/)   
[51：N 皇后](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_51.cpp)                    已完成      
[37：解数独](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_37.cpp)                    已完成    
[52：N 皇后 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_52.cpp)                    已完成   

# 学习总结

n & (n - 1)的作用：n的二进制的**最低位**为1的变为0。如  n = 10100（二进制），那么n - 1 = 10011。                    n & (n - 1) = 10000

DFS  和 **并查集**

Leetcode **547**题 [朋友圈](https://leetcode-cn.com/problems/friend-circles)  Leetcode**200**题 [岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) Leetcode**130**题 [被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

547题并查集在合并时，先比较（i与j不相等） x = find(i) 与 y = find(j)，如果x与y不相等，pa[x] = y。注意如果某一行数据为    [1, 1, 1]，第一次比较时p[0] = 1, p[1] = 1，第2次比较时p[1] = 2，p[2] = 2。这会导致 p[0] = 2，        p[0] = 1, p[1] = 2（但此时p[0]为1）！故 写代码时要注意细节~

分析“单词搜索 II”用 Tire 树实现的时间复杂度



总结 **双向 BFS** 代码模版

python：用集合set() 替换队列deque()，两个集合：一个从前往后扩散，一个从后往前扩散。当前后相遇时，程序终止，否则视为搜索不到。刚开始从前向后搜索，每一次把所有扩散得到的节点先存储在一个临时的set中，将其赋给front。再比较此时front的节点数和back的节点数，哪一个节点数少从哪里开始搜索以此节省时间！

```python
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
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
            if len(front) > len(back):#从少的继续扩散
                front, back = back, front
        return 0
```

AVL旋转操作：

左旋：右右子树；右旋：左左子树；

左右子树：左右旋；

![左右旋](C:\Users\CJJ\AppData\Roaming\Typora\typora-user-images\image-20200814162719915.png)

右左子树：与左右子树对称

AVL相比红黑树提供了更快的**查询**操作，因为AVL严格平衡；红黑树提供更快插入和删除操作，因为AVL旋转操作更多；AVL要存储平衡因子信息，红黑树需要的信息少只要一个bit存黑或红；读操作多写操作少选AVL，否则选红黑树。
# 简 单

[70：爬楼梯](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_70.cpp)                    已完成     
[191：位 1 的个数](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_191.cpp)                    已完成   
[231：2 的幂](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_231.cpp)                    已完成   
[190：颠倒二进制位](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_05/Leetcode_190.cpp)                    已完成   

# 中 等

[208：实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/#/description)                    已完成   
[547：朋友圈](https://leetcode-cn.com/problems/friend-circles)                    已完成   
[200：岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)  
[130：被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)                     已完成   
[36：有效的数独](https://leetcode-cn.com/problems/valid-sudoku/description/)                     已完成   
[22：括号生成](https://leetcode-cn.com/problems/generate-parentheses/)  
[127：单词接龙](https://leetcode-cn.com/problems/word-ladder/)  
[最小基因变化](https://leetcode-cn.com/problems/minimum-genetic-mutation/)   
[338：比特位计数](https://leetcode-cn.com/problems/counting-bits/description/)                    已完成      

# 困 难

[单词搜索 II ](https://leetcode-cn.com/problems/word-search-ii/)   
[51：N 皇后](https://leetcode-cn.com/problems/n-queens/)                    已完成      
[解数独](https://leetcode-cn.com/problems/sudoku-solver/#/description)   
[52：N 皇后 II ](https://leetcode-cn.com/problems/n-queens-ii/description/)                    已完成   

# 学习总结

n & (n - 1)的作用：n的二进制的最低位为1的变为0。如  n = 10100（二进制），那么n - 1 = 10011。                    n & (n - 1) = 10000

DFS  和 **并查集**

Leetcode **547**题 [朋友圈](https://leetcode-cn.com/problems/friend-circles)  Leetcode**200**题 [岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) Leetcode**130**题 [被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)

547题并查集在合并时，先比较（i与j不相等） x = find(i) 与 y = find(j)，如果x与y不相等，pa[x] = y。注意如果某一行数据为    [1, 1, 1]，第一次比较时p[0] = 1, p[1] = 1，第2次比较时p[1] = 2，p[2] = 2。这会导致 p[0] = 2，        p[0] = 1, p[1] = 2（但此时p[0]为1）！故 写代码时要注意细节~

分析“单词搜索 II”用 Tire 树实现的时间复杂度

总结双向 BFS 代码模版b
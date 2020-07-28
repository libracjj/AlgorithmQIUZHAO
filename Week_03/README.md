# 简 单

[169：多数元素](https://leetcode-cn.com/problems/majority-element/description/) 			  *已完成*  			  

[860：柠檬水找零](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_860.cpp) 			  *已完成*  			  

[买卖股票的最佳时机 II ](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

[455：分发饼干](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_455.cpp) 			  *已完成*  			  

[模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/description/)

# 中 等

[50：Pow(x, n) ](https://leetcode-cn.com/problems/powx-n/)			  *已完成* 

[78：子集](https://leetcode-cn.com/problems/subsets/)			  *已完成* 

[17：电话号码的字母组合](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_17.cpp) 			  *已完成*  			  

[单词接龙](https://leetcode-cn.com/problems/word-ladder/description/)

[岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)

[扫雷游戏](https://leetcode-cn.com/problems/minesweeper/description/)

[跳跃游戏](https://leetcode-cn.com/problems/jump-game/)

[33：搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

[搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)

[寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)

# 困 难

[51：N 皇后](https://leetcode-cn.com/problems/n-queens/) 			  *已完成*  

[单词接龙 II ](https://leetcode-cn.com/problems/word-ladder-ii/description/)

[跳跃游戏 II ](https://leetcode-cn.com/problems/jump-game-ii/)



# 学习总结

Leetcode 17题 电话号码的字母组合：在递归时，当字符串长度与输入的数字串一致时，加入结果再return。首先获得当前数字对应的字母们并在字符串尾加入一个字母，然后向下递归（下一个数字）。因为某一个结果是string类型，不是vector，所以无pop_back()！令：当输入为 **“”**，要返回 **[]** 而不是 **[""]**      

Leetcode 50题 x的n次幂：注意n首先要转化为long long型（**C++**），再套用快速幂模板！python中不存在此问题      

分治法的思路是：有一个递归终止条件，把问题分解成多个子问题，子问题有解后合并起来得到最终的问题的答案

比如x的n次幂可用分治法：

```python
def fastpow(a, n):
    if n == 0:
        return 1.0
    elif n < 0:
        return fastpow(a, -n)
    elif n % 2:
        return fastpow(a * a, n // 2) * a
    else:
        return fastpow(a * a, n // 2)
```


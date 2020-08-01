# 简 单

[169：多数元素](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_169.cpp) 			  *已完成*  			  

[860：柠檬水找零](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_860.cpp) 			  *已完成*  			  

[122：买卖股票的最佳时机 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_122.cpp) 			  *已完成*  			  

[455：分发饼干](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_455.cpp) 			  *已完成*  			  

[模拟行走机器人](https://leetcode-cn.com/problems/walking-robot-simulation/description/)

# 中 等

[50：Pow(x, n) ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_50.cpp)			  *已完成* 

[78：子集](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_78.cpp)			  *已完成* 

[17：电话号码的字母组合](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_17.cpp) 			  *已完成*  			  

[127：单词接龙](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/leetcode_127.py)			  *已完成*  			  			  

[200：岛屿数量](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_200.cpp)			  *已完成*  			  

[529：扫雷游戏](https://leetcode-cn.com/problems/minesweeper/description/)

[55：跳跃游戏](https://leetcode-cn.com/problems/jump-game/)			  *已完成*  			  

[33：搜索旋转排序数组](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_33.cpp)			  *已完成*  			  

[74：搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)			  *已完成*  			  

[153：寻找旋转排序数组中的最小值](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_153.cpp)			  *已完成*  			  

# 困 难

[51：N 皇后](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_51.cpp) 			  *已完成*  

[单词接龙 II ](https://leetcode-cn.com/problems/word-ladder-ii/description/)

[45：跳跃游戏 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_45.cpp)			  *已完成*  			  



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

**二分查找：**

（基本二分）如果right = nums.size() - 1，搜索区间为[left, right]，决定了 while (left <= right)，也决定了left = **mid + 1**和	right = **mid - 1** （推荐此法）

（寻找左侧边界）若right = nums.size()，搜索区间为[left, right)，决定了 while (left < right)，也决定了left = **mid + 1**和			 right = **mid**。
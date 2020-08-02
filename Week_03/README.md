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

[529：扫雷游戏](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_529.cpp)			  *已完成*  			  

[55：跳跃游戏](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_55.cpp)			  *已完成*  			  

[33：搜索旋转排序数组](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_33.cpp)			  *已完成*  			  

[74：搜索二维矩阵](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_74.cpp)			  *已完成*  			  

[153：寻找旋转排序数组中的最小值](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_153.cpp)			  *已完成*  			  

# 困 难

[51：N 皇后](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_51.cpp) 			  *已完成*  			  

[126：单词接龙 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_03/Leetcode_126.py)			  *已完成*  			  

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

  

**二分查找**

（基本二分）如果right = nums.size() - 1，搜索区间为[left, right]，决定了 while (left <= right)，也决定了		left = **mid + 1**和 right = **mid - 1** （推荐此法）   

（寻找左侧边界）若right = nums.size()，搜索区间为[left, right)，决定了 while (left < right)，也决定了			left = **mid + 1**和  right = **mid**。    

  

**深度优先和广度优先搜索**（非递归版）  

C++：   

**深度**：使用栈（1重循环），访问栈顶记为cur（stk.top()），取出栈顶（stk.pop()）。判断当前值是否访问过，如果**访问**过则continue，否则打上标记。获取cur的孩子个数  （n：cur->children.size()），从最后一个孩子开始到0，依次入栈。     

**广度**：使用队列（2重循环），首先获取队头记为temp（q.front()），再弹出队头（q.pop()）。判断当前值是否**访问**过，如果访问过则continue，否则打上标记。再一个循环，依次将temp的孩子们入队。     

n叉树层次遍历时，需要先获取队列的长度！   

  

**Leetcode126题单词接龙II**：

用python可简单实现！    

首先生成单词邻接表，用'*'代替某一个字符作为字典的键，相应的单词作为值。接下来准备bfs，首先初始化队列加入(beginWord, 已访问过的单词)，res存储结果，visited为单词及到beginWord的距离。只要队列不为空就循环，获取最左边的元素，如果word为endWord把结果加入到res，接下来枚举与当前单词相似的新词，若新词未被访问过或者当前词到beginWord的距离小于等于访问该词的时间：那么就把该词入队 (word, _list[:] + [child])，打上标记表示已访问（visited[child] = dist）。最终返回res。   
# 中 等

[64：最小路径和](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_64.cpp)          *已完成*          

[91：解码方法](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_91.cpp)          *已完成*          

[221：最大正方形](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_221.cpp)          *已完成*          

[621：任务调度器](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_621.cpp)          *已完成*          

[647：回文子串](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_647.cpp)          *已完成*          

# 困 难

[32：最长有效括号](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_32.cpp)          *已完成*          

[72：编辑距离](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_72.cpp)          *已完成*          

[363：矩形区域不超过 K 的最大数值和](https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/)

[403：青蛙过河](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_403.cpp)          *已完成*          

[410：分割数组的最大值](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_410.py) **二分**                    *已完成*          

[552：学生出勤记录 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_552.py)          *已完成*          

[76：最小覆盖子串](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_76.cpp) **滑动窗口**                    *已完成*                     

[312：戳气球](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_04/Leetcode_312.cpp)          *已完成*          

# 学习总结

Leetcode62题 [不同路径](https://leetcode-cn.com/problems/unique-paths/)

```C++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[j] = 1;
                }
                if (i >= 1 && j >= 1){
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp.back();
    }
};
```

Leetcode63题 [不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)    

首先获取行数m以及列数n，声明dp大小为n。判断obstacleGrid[0] [0]是否为0，若是则dp[0] = 1。for循环i从0到m，再一个循环j从0到n，如果obstacleGrid[i] [j]为1，那么dp[j] = 0，并开始下一次循环（continue）。如果 j - 1 >= 0 且 obstacleGrid[i] [j - 1] 为0，那么 dp[j] = dp[j] + dp[j - 1]，最后返回dp.back()。

Leetcode53题 [最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

注意输入可能只有一个数且该数小于0！所以首先是sum += nums[i]，然后让ans在ans和sum中选取更大的值，最后更新sum的值是0还是sum。

Leetcode221题 [最大正方形](https://leetcode-cn.com/problems/maximal-square/)

dp[i] [j] 表示以（i, j）为右下角，正方形边长的最大值。对于某个位置（i, j），若值为0，则 dp[i] [j] = 0。若为1：由其上、左及左上的dp值决定。要注意边界条件：如果 i 或 j 为0，dp[i] [j]只可能为1。

Leetcode**312**题 [戳气球](https://leetcode-cn.com/problems/burst-balloons/)

dp[i] [j]表示**开区间**（i, j）戳破所有气球后，能获得的最大硬币数。k表示（i, j）之间的一个索引，dp[i] [j]就为戳破k左边所有的气球得到的硬币（dp[i] [k]）、戳破k右边所有的气球得到的硬币（dp[k] [j]）再加上戳破k得到硬币（nums[i] * nums[k] * nums[j]）

Leetcode**647**题 [回文子串](https://leetcode-cn.com/problems/palindromic-substrings/)

dp[i] [j]表示[i, j]范围内字符是否为回文串，i 从后向前遍历，j 从 i 向后遍历。若s[i]与s[j]相等，如果满足 s[i] 与 s[j] 的距离小于等于2、或者满足 [i+1, j-1] 之间为回文串即 dp[i+1] [j-1] 为1那么ans += 1。

Leetcode**72题** [编辑距离](https://leetcode-cn.com/problems/edit-distance/)

dp[i] [j] 表示s1[0..i] 和 s2[0..j] 的最小编辑距离，如果s1[i] == s2[j]则 dp[i] [j] = dp[i-1] [j-1]；否则选择插入（ dp[i] [j-1] + 1，i 插入与 s[j] 一样的字符，j 前移）、删除（dp[i-1] [j]，s[i]  删除，前移 i）及替换（s1[i] 替换成 s2[j]，i 和 j 都前移）的最小代价


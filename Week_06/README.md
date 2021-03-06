# 简 单

[1122：数组的相对排序](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_1122.cpp)           *已完成*          

[242：有效的字母异位词](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_242.cpp)           *已完成*          

[387：字符串中的第一个唯一字符](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_387.cpp)           *已完成*          

[541：反转字符串 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_541.cpp)           *已完成*          

[151：翻转字符串里的单词](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_151.py)           *已完成*          

[557：反转字符串中的单词 III ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_557.py)           *已完成*          

[917：仅仅反转字母](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_917.cpp)           *已完成*          

[205：同构字符串](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_205.py)           *已完成*          

[680：验证回文字符串 Ⅱ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_680.cpp)           *已完成*          

# 中 等

[146：LRU 缓存机制](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_146.py)           *已完成*          

[56：合并区间](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_56.cpp)           *已完成*          

[300：最长上升子序列](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_300.cpp)           *已完成*          

[91：解码方法](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_91.cpp)           *已完成*          

[8：字符串转换整数 (atoi)](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_8.cpp)           *已完成*          

[438：找到字符串中所有字母异位词](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_438.cpp)           *已完成*          

[5：最长回文子串](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_5.cpp)           *已完成*          

# 困 难

[493：翻转对](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_493.cpp)           *已完成*          

[32：最长有效括号](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_32.cpp)           *已完成*          

[818：赛车](https://leetcode-cn.com/problems/race-car/)

[44：通配符匹配](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_44.cpp)           *已完成*          

[115：不同的子序列](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_06/Leetcode_115.cpp)           *已完成*          

# 学习总结

布隆过滤器：如果一个元素所对应的二进制位有一个不为1，说明该元素不在布隆过滤器的索引里。当布隆过滤器把所有元素都插入完成，当一个测试元素所对应的二进制位都为1，该元素**可能**存在于布隆过滤器中。   



选择排序：在未排序序列中找到最小（大）元素，存放到排序序列中

```c++
template<typename T>
void selection_sort(vector<T>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
                int min = i;
                for (int j = i + 1; j < arr.size(); j++)
                        if (arr[j] < arr[min])//遍历寻找最小值
                                min = j;
                swap(arr[i], arr[min]);//交换
        }
}
```

插入排序：对于未排序数组，从已排序序列中从后往前扫描，找到对应位置插入

```c++
template<typename T>
void insertion_sort(vector<T>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while((j >= 0) && (key < arr[j])) {
            arr[j+1] = arr[j];//往后移
            j--;//向前寻找
        }
        arr[j+1] = key;//正确的位置
    }
}
```

冒泡排序：相邻元素如果逆序，则交换。

```c++
template<typename T>
void bubble_sort(vector<T>& arr) {
    int len = arr.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
                if (arr[j] > arr[j+1])
                    swap(arr[j], arr[j+1]);
        }
    }
}
```

[不同路径 2 ](https://leetcode-cn.com/problems/unique-paths-ii/) 状态转移方程

x >= 1 且 y >= 1：f(x, y) = f(x - 1, y) + f(x, y - 1)

x = 0 且 y = 0：f(x, y) = 1（无障碍物）

x = 0：f(x, y) = f(x, y - 1)

y = 0：f(x, y) = f(x - 1, y)
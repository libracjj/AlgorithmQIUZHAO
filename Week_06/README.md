# 简 单

[1122：数组的相对排序](https://leetcode-cn.com/problems/relative-sort-array/)           已完成          

[242：有效的字母异位词](https://leetcode-cn.com/problems/valid-anagram/)           已完成          

[字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/)           已完成          

[反转字符串 II ](https://leetcode-cn.com/problems/reverse-string-ii/)

[151：翻转字符串里的单词](https://leetcode-cn.com/problems/reverse-words-in-a-string/)           已完成          

[反转字符串中的单词 III ](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

[仅仅反转字母](https://leetcode-cn.com/problems/reverse-only-letters/)

[同构字符串](https://leetcode-cn.com/problems/isomorphic-strings/)

[验证回文字符串 Ⅱ](https://leetcode-cn.com/problems/valid-palindrome-ii/)

# 中 等

[146：LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/#/)

[56：合并区间](https://leetcode-cn.com/problems/merge-intervals/)           已完成          

[最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

[解码方法](https://leetcode-cn.com/problems/decode-ways/)

[字符串转换整数 (atoi) ](https://leetcode-cn.com/problems/string-to-integer-atoi/)

[找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)

[5：最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

# 困 难

[493：翻转对](https://leetcode-cn.com/problems/reverse-pairs/)           已完成          

[32：最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)           已完成          

[赛车](https://leetcode-cn.com/problems/race-car/)

[通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)

[不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)

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

f(x, y) = f(x - 1, y) + f(x, y - 1)
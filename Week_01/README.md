## 第 一 周  

### 简单

 [删除排序数组中的重复项](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_26.cpp/) *已完成*   
 [旋转数组](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_189.cpp)  *已完成*  
 合并两个有序链表  
 [合并两个有序数组](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_88.py) *已完成*   
 [两数之和](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_1.cpp) *已完成*   
 [移动零](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_283.cpp) *已完成*   
 [加一](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_66.cpp)  *已完成*   
 [有效的字母异位词](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_242.cpp)   *已完成*      

### 中等 

 设计循环双端队列   
 字母异位词分组       

### 困难

 接雨水       

# 学习总结

## C++ queue源码   

queue、priority_queue均位于<stl_queue.h>中

`protected:`    

`_Sequence c;//底层容器，默认为deque容器，用户可自行指定容器类型`     

关键是"queue"的操作：

[**empty**](http://www.cplusplus.com/reference/queue/queue/empty/) 判断容器是否为空：函数类型为bool，返回 c.**empty**()  

[**size**](http://www.cplusplus.com/reference/queue/queue/size/) 返回容器中元素的个数：返回 c.**size**()

[**front**](http://www.cplusplus.com/reference/queue/queue/front/) 返回队头元素的引用：返回 c.**front**()

[**back**](http://www.cplusplus.com/reference/queue/queue/back/) 返回队尾元素的引用：返回 c.**back**()

[**push**](http://www.cplusplus.com/reference/queue/queue/push/) **只能**在队尾新增元素：操作为 c.**push_back**(__x)

[**emplace**](http://www.cplusplus.com/reference/queue/queue/emplace/) 利用 c.**emplace_back**()

[**pop**](http://www.cplusplus.com/reference/queue/queue/pop/) **只能**在队头移除元素：c.**pop_front**()

[**swap**](http://www.cplusplus.com/reference/queue/queue/swap/) 交换两个队列的内容

## C++ priority_queue源码

缺省情况下是以**vector**为底层容器，再加上**heap**处理规则实现，按照权值高低自动排序

[**empty**](http://www.cplusplus.com/reference/queue/priority_queue/empty/) 检查底层容器是否为空

[**size**](http://www.cplusplus.com/reference/queue/priority_queue/size/) 返回底层容器中的元素数

[**top**](http://www.cplusplus.com/reference/queue/priority_queue/top/) 返回队列的第一个元素的只读（常量）引用

`return c.front();`   

[**push**](http://www.cplusplus.com/reference/queue/priority_queue/push/) 添加给定的元素 value 到 priority_queue 中：

`c.push_back(std::move(__x));`   
`std::push_heap(c.begin(), c.end(), comp);`

[**emplace**](http://www.cplusplus.com/reference/queue/priority_queue/emplace/) 向优先队列添加新元素。该元素是就地构造的，传递参数作为其构造函数的参数

[**pop**](http://www.cplusplus.com/reference/queue/priority_queue/pop/) 移除堆顶元素

`__glibcxx_requires_nonempty();`   
`std::pop_heap(c.begin(), c.end(), comp);`   
`c.pop_back();`

[**swap**](http://www.cplusplus.com/reference/queue/priority_queue/swap/) 交换两个优先队列的内容

[优先队列参考](https://blog.csdn.net/qq_38289815/article/details/106748014)
## 第一周  

### 简单

 [删除排序数组中的重复项](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_01/Leetcode_26.cpp/) *已完成*   
 旋转数组  
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

位于<stl_queue.h>中，基于某种容器作为底部结构的，默认容器是deque容器。  

`protected:`    

`_Sequence c;//底层容器，默认为deque容器，用户可自行指定容器类型`     

关键是"queue"的操作：

判断容器是否为空：函数类型为bool，返回 **c.empty()**  

返回容器中元素的个数：返回 **c.size()**

返回队头元素的引用：返回 **c.front()**

返回队尾元素的引用：返回 **c.back()**

**只能**在队尾新增元素：操作为 c.push_back(__x);

**只能**在队头移除元素：c.pop_front();

C++ priority_queue






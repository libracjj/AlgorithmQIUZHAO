# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 15:18:23 2020

@author: CJJ
"""


#641. 设计循环双端队列
#https://leetcode-cn.com/problems/design-circular-deque/
"""
关键是几个函数的实现
先实现 判断队空、队满
取队头元素 队尾元素
队头插入（先移指针再赋值）、队尾插入（先赋值再移指针）
队头删除（指针右移）、 队尾删除（指针左移）
"""
class MyCircularDeque(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        长度为k时占用k+1的空间，多出来的空间用来区分isEmpty和isFull
        """
        self.front = 0
        self.rear = 0
        self.capacity = k + 1
        self.arr = [0 for i in range(self.capacity)]

    def insertFront(self, value):
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        """
        队头 前一个元素赋值，首先移动队头指针，再赋值
        """
        self.front = (self.front - 1 + self.capacity) % self.capacity
        self.arr[self.front] = value
        return True

    def insertLast(self, value):
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False

        """
        先赋值，再移动队尾指针
        """
        self.arr[self.rear] = value
        self.rear = (self.rear + 1) % self.capacity
        return True
        

    def deleteFront(self):
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        """
        队头指针右移
        """		
        self.front = (self.front + 1) % self.capacity
        return True
        

    def deleteLast(self):
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        """
        队尾指针左移
        """
        self.rear = (self.rear - 1 + self.capacity) % self.capacity
        return True

        

    def getFront(self):
        """
        Get the front item from the deque.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        return self.arr[self.front]
        

    def getRear(self):
        """
        Get the last item from the deque.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        return self.arr[(self.rear - 1 + self.capacity) % self.capacity]
        

    def isEmpty(self):
        """
        Checks whether the circular deque is empty or not.
        :rtype: bool
        队头指针与队尾指针指向同一位置，为空队
        """
        return self.front == self.rear

    def isFull(self):
        """
        Checks whether the circular deque is full or not.
        :rtype: bool
        队尾指针+1 取模 队列长度 与队头指针位置一致，队满
        """
        return (self.rear + 1) % self.capacity == self.front
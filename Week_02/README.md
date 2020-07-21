## 简 单

[N 叉树的后序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_590.cpp)          *已完成*

[N 叉树的前序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_589.cpp)          *已完成*

## 中 等

[二叉树的中序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_94.cpp)          *已完成*

[二叉树的前序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_144.cpp)          *已完成*

[N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)          *已完成*		  

[丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)          *已完成*		

[前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)		

[二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)		

[从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)		

[组合](https://leetcode-cn.com/problems/combinations/)		

[全排列](https://leetcode-cn.com/problems/permutations/)		

[全排列 II ](https://leetcode-cn.com/problems/permutations-ii/)		

# 学习总结

堆的底层实现可以看作是一个满二叉树（除了叶子节点）。所以可用**数组**来实现heap。

关键的操作有3个(已大顶堆为例，根节点最大的称为大顶堆)：查找最大值、插入、删除

**查找最大值**

返回heap[0]。

**插入**

首先将元素插入到数组末尾，然后从下往上调整，不断与其父节点比较。如果该值比父节点的值大，父节点下来，直到找到要插入的位置（不再大于父节点），将值插入即可。

```c++
while (i > 0 && insertval > heap[parent[i]]) {
	heap[i] = heap[parent[i]];
	i = parent[i];
}
```

**删除**（最大值）

从上向下操作：首先堆尾替换顶部，不断比较左右儿子节点哪一个更大，若值更大的儿子节点大于该值，这个儿子节点向上**放**，直至找到堆尾元素的节点的位置（此时比左右儿子节点的值都要大）。


## 简 单

[N 叉树的后序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_590.cpp)          *已完成*

[N 叉树的前序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_589.cpp)          *已完成*

## 中 等

[二叉树的中序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_94.cpp)          *已完成*

[二叉树的前序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_144.cpp)          *已完成*

[N 叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)          *已完成*		  

[丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)          *已完成*		

[前 K 个高频元素](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_347.cpp)          *已完成*		

[二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)          *已完成*          			

[从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)          			

[组合](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_77.cpp)          *已完成*			

[全排列](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_46.cpp)          *已完成*		

[全排列 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_47.cpp)          *已完成*		

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

## 最小生成树

### Prim  

```c++
//默认图是连通的
int prim(int n)
{
    int sum = 0, i, k;
    visited[0] = 1;//V0 已并入集合U中
    for (i = 1; i < n; i++) {//选择其余n-1条边，初始化最小花费
        low[i] = map[0][i];
        visited[i] = 0;
    }
    
    for (i = 1; i < n; i++) {//循环找每一次的最小值
        int minc = INF;//可设置一个很大的值
        int j = 0;
        for (k = 1; k < n; k++)
            if (low[k] < minc && visited[k] == 0) {//更新最小值
                minc = low[k];
                j = k;
            }
        
        sum += minc;//最小值累加
        visited[j] = 1;//visited数组置为1，标志将这个点加入集合U
        
        for (k = 1; k < n; k++)//n-1次循环
            if (map[j][k] < low[k] && !visited[k])//下一个节点未访问，且权值小于当前值
                low[k] = map[j][k];//更新low的值
    }
    return sum;
}
```

### Kruskal

```c++
int cmp(const int i, const int j) {return w[i] < w[j];}
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int kruskal()
{
    int cnt = 0,x,y,i,ans = 0;
    for (i = 0; i < n; i++) p[i] = i;//并查集初始化
    for (i = 0; i < m; i++) r[i] = i;//边编号
    sort (r, r + m , cmp);
    for (i = 0; i < m; i++){
        //取出未加入的边权最小的边的编号 
        int e = r[i]; x = find(u[e]); y = find(v[e]);
        if(x != y) {ans += w[e]; p[x] = y; cnt++; }
    }
    if(cnt < n - 1) ans = 0;//找不到最小生成树 
    return ans;
}
```


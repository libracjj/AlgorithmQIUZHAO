点击 链接 直接跳 我的解答 ^_^

## 简 单

[590: N 叉树的后序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_590.cpp)          *已完成*

[589: N 叉树的前序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_589.cpp)          *已完成*

## 中 等

[94: 二叉树的中序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_94.cpp)          *已完成*

[144: 二叉树的前序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_144.cpp)          *已完成*

[429: N 叉树的层序遍历](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_429.cpp)          *已完成*		  

[264: 丑数](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_264.cpp)          *已完成*		

[347: 前 K 个高频元素](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_347.cpp)          *已完成*		

[236: 二叉树的最近公共祖先](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_236.cpp)          *已完成*          			

[105: 从前序与中序遍历序列构造二叉树](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_105.cpp)          *已完成*  

[77: 组合](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_77.cpp)          *已完成*			

[46: 全排列](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_46.cpp)          *已完成*		

[47: 全排列 II ](https://github.com/libracjj/AlgorithmQIUZHAO/blob/master/Week_02/Leetcode_47.cpp)          *已完成*		

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

## 拓扑排序

有向无环图的所有顶点的线性序列

### 贪心

1、从 DAG 图中选择一个 没有前驱（即**入度**为**0**）的顶点并输出。  
2、从图中删除该顶点和所有以它为起点的有向边。   
3、重复 1 和 2 直到当前的 DAG 图为空或**当前图中不存在无前驱的顶点为止**。后一种情况说明有向图中必然存在环。   

## [最短路径](http://www.bilibili.com/video/av25829980)

### Dijkstra

[HDU 2544](http://acm.hdu.edu.cn/showproblem.php?pid=2544)

```c++
memset(v, 0, sizeof(v));
for (int i = 0; i < n; i++) d[i] = (i == 0 ? 0 : INF);
for (int i = 0; i < n; i++) {
    int x, m = INF;
    //选出d值最小的节点 x
    for (int y = 0; y < n; y++) if(!v[y] && d[y] <= m){m = d[y]; x = y;}
    v[x] = 1;//给节点x标记
    //从x出发的所有边(x,y)，更新d[y]
    for (int y = 0; y < n; y++) d[y] = min(d[y], d[x] + w[x][y]);
}
```



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
    int cnt = 0, x, y, i, ans = 0;
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


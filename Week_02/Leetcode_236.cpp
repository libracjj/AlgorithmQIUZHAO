/*
236. 二叉树的最近公共祖先
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

1. 左右子树的返回值都不为空, 由于值唯一左右子树的返回值就是p和q, 此时root为LCA
2. 如果左右子树返回值只有一个不为空, 说明只有p和q存在与左或右子树中, 最先找到的那个节点为LCA
3. 左右子树返回值均为空, p和q均不在树中, 返回NULL
*/
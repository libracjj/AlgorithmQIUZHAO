/*
236. 二叉树的最近公共祖先
https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

1. 左右子树的返回值都不为空, 由于值唯一左右子树的返回值就是p和q, 此时root为LCA
2. 如果左右子树返回值只有一个不为空, 说明只有p和q存在与左或右子树中, 最先找到的那个节点为LCA
3. 左右子树返回值均为空, p和q均不在树中, 返回NULL
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL && right == NULL)  return NULL;
        else if (left != NULL && right != NULL) return root;
        else return left == NULL ? right : left;

    }
};
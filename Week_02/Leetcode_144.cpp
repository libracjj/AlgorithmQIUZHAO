//144. 二叉树的前序遍历
//https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
    vector<int> path;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root) {
            path.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return path;
    }
};
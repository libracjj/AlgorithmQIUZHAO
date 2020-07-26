/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34562/Sharing-my-straightforward-recursive-solution
105. 从前序与中序遍历序列构造二叉树
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe)//终止
            return NULL;
        TreeNode* node = new TreeNode(preorder[ps]);//作为根节点
        int pos;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == node->val) {//寻找根节点 在中序遍历中的位置
                pos = i;
                break;
            }
        }
//前序：[ps+1, ps + pos - is] [pe - (ie - pos) + 1, pe]
//中序：[is, pos - 1] and [pos + 1, ie]

        node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
        return node;
    }
};
/*
589. N叉树的前序遍历
https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/

https://leetcode.com/problems/n-ary-tree-preorder-traversal/discuss/149093/C%2B%2B-44ms-beats-100-both-iterative-and-recursive
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        if (!root) return {};

        stk.push(root);
        while (!stk.empty()){
            Node* cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            int n = cur->children.size();
            for (int i = n - 1; i >= 0; i--){
                if (cur->children[i]) stk.push(cur->children[i]);
            }
        }
        return res;
    }
};
/*
//递归做法
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(!root) return res;
        res.push_back(root->val);
        for (auto c : root->children) {
            preorder(c);
        }
        return res;
    }
};
*/

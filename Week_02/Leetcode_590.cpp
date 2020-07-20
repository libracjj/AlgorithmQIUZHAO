/*
590. N叉树的后序遍历
https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/
迭代法
*/
/*

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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return {};
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* temp = stk.top();
            stk.pop();
            res.push_back(temp->val);
            for (auto i: temp->children) {
                stk.push(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
/*
class Solution {
public:
    vector<int> path;
    vector<int> postorder(Node* root) {
        if (!root)
            return path;
        for (auto c : root->children) {
            postorder(c);
        }
        path.push_back(root->val);
        return path;
    }
};
*/
/*
429. N叉树的层序遍历
https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
题解：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/solution/ncha-shu-ceng-ci-bian-li-by-libracjj/
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
//国际站参考：https://leetcode.com/problems/n-ary-tree-level-order-traversal/discuss/159086/Basic-C%2B%2B-iterative-solution-with-detailed-explanations.-Super-easy-for-beginners.
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
           int size = que.size();//队列大小，即当前层节点的数量
           vector<int> cur;
           for (int i = 0; i < size; i++) {
               Node *temp = que.front();//获取队头
               que.pop();//弹出该节点
               cur.push_back(temp->val);
               for (auto c : temp->children) {
                   que.push(c);//孩子依次进入队列
               }
            }
            res.push_back(cur);
        }
        return res;
    }
};
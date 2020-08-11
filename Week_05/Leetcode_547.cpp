/*
https://leetcode-cn.com/problems/friend-circles/
547. 朋友圈
https://leetcode.com/problems/friend-circles/discuss/101354/C%2B%2B-Clean-Code-DFSorUnionFind
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<int> pa(n, 0);
        for (int i = 0; i < n; i++) { pa[i] = i; }   
        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {//避免重复   
                if (M[i][j]) {
                    int x = find(i, pa);
                    int y = find(j, pa);
                    if (x != y) {       
                        pa[x] = y;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }
private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};
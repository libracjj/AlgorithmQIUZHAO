/*
https://leetcode-cn.com/problems/task-scheduler/
621. 任务调度器
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < len; i++) {
            cnt[tasks[i] - 'A']++;
        }
        sort(cnt.begin(), cnt.end());
        int Maxcnt = 0;
        for (int i = 25; i >= 0; i++) {
            if (cnt[i] != cnt[25])
                break;
            Maxcnt++;
        }
        return max(len, (cnt[25] - 1) * (n + 1) + Maxcnt);
    }
};
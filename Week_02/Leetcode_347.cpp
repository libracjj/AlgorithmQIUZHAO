/*
347. 前 K 个高频元素
https://leetcode-cn.com/problems/top-k-frequent-elements/
*/
//https://leetcode.com/problems/top-k-frequent-elements/discuss/81624/C%2B%2B-O(n-log(n-k))-unordered_map-and-priority_queue(maxheap)-solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto num : nums) {
            map[num]++;
        }
        priority_queue< pair<int, int> > pq;
        vector<int> res;
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(make_pair(it->second, it->first));//第一个为频次
            if(pq.size() > map.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};
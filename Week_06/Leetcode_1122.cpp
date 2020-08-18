/*
https://leetcode-cn.com/problems/relative-sort-array/
1122. 数组的相对排序
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int map[1005] = {0};
        for (int i = 0; i < arr1.size(); i++) {
            map[arr1[i]]++;
        }
        int j = 0;
        for (int i = 0; i < arr2.size(); i++) {
            while (map[arr2[i]]) {
                arr1[j++] = arr2[i];
                map[arr2[i]]--;
            }
        }
        for (int i = 0; i <= 1000; i++) {
            if (map[i] != 0) {
                while(map[i] && j < arr1.size()) {
                    arr1[j++] = i;
                    map[i]--;
                }
            }
        }
        return arr1;
    }
};
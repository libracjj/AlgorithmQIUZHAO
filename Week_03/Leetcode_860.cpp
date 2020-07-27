/*
https://leetcode-cn.com/problems/lemonade-change/
860. 柠檬水找零
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int m_5 = 0, m_10 = 0;
        for (int i : bills) {
            if (i == 5) m_5++;
            else if (i == 10) {m_5--, m_10++;}
            else if (m_10 > 0) {m_5--, m_10--;}
            else m_5 -= 3;

            if (m_5 < 0) return false;
        }
        return true;
    }
};
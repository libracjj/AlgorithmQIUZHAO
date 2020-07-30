/*
https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
122. 买卖股票的最佳时机 II
利用 贪心法求解
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] < prices[i])
                sum += prices[i] - prices[i - 1];
        }
        return sum;
    }
};
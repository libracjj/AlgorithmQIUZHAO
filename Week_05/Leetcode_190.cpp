/*
https://leetcode-cn.com/problems/reverse-bits/
190. 颠倒二进制位
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 32;
        while (i--) {
            ans <<= 1;//结果左移1位
            ans += n & 1;//加上最低位是否为1
            n >>= 1;//n右移
        }
        return ans;
    }
};
/*
https://leetcode-cn.com/problems/power-of-two/
231. 2的幂
*/
//1：去除二进制中最右边的 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;
        long long x = n;
        return (x & (x - 1)) == 0;
    }
};
//2：获取二进制中最右边的 1，x与-x进行与运算，-x二进制可表示为x取反再+1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;
        long long x = n;
        return (x & (-x)) == x;
    }
};
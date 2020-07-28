/*
50. Pow(x, n)
https://leetcode-cn.com/problems/powx-n/
*/
class Solution {
public:
    double binpow(double x, long long a) {
        double r = 1.0;
        while (a) {
            if (a & 1)
                r *= x;
            x *= x;
            a >>= 1;
        }
        return r;
    }
    double myPow(double x, int n) {
        long long N = n;//note!
        return n >= 0 ? binpow(x, N) : 1.0 / binpow(x, -N);
    }
};
class Solution {
public:
    // 可以用矩阵快速幂来优化
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int sum = 0, n1 = 1, n2 = 2;
        for (int i = 3; i <= n; i++) {
            sum = n1 + n2;
            n1 = n2;
            n2 = sum;
        }
        return sum;
    }
};

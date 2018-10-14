class Solution {
public:
#if 0
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        long long prev = 1, i;
        for (i = 2; i < x; i++) {
            if (i * i <= x) {
                prev = i;
                continue;
            } else {
                break;
            }
        }
        return (int)prev;
    }
#endif
    // 数值计算-牛顿法
    int mySqrt(int x) {
        double ans    = x;
        double delta  = 0.0001;
        while (fabs(pow(ans, 2) - x) > delta) {
            ans = (ans + x / ans) / 2;
        }
        return ans;
    }

};

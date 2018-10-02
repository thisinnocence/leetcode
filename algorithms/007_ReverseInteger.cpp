class Solution {
public:
    int reverse(int x){
        long long re = 0;
        while(x){
            re = re * 10 + x % 10;
            x /= 10;
        }
        return re > INT_MIN && re < INT_MAX ? re : 0;
    }
};

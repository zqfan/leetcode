class Solution {
public:
    int reverse(int x) {
        long rx = 0;
        while ( x ) {
            rx = rx * 10 + x % 10;
            x /= 10;
        }
        return INT_MIN <= rx && rx <= INT_MAX ? rx : 0;
    }
};

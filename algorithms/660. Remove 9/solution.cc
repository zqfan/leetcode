class Solution {
public:
    int newInteger(int n) {
        int base9 = 0, p = 1;
        while ( n > 0 ) {
            base9 += n % 9 * p;
            n /= 9;
            p *= 10;
        }
        return base9;
    }
};

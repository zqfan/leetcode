class Solution {
public:
    int findNthDigit(int n) {
        --n;
        int width = 1, first = 1;
        while ( n / 9 / width / first >= 1 ) {
            n -= 9 * width * first;
            ++width;
            first *= 10;
        }
        return to_string(first + n / width)[n % width] - '0';
    }
};

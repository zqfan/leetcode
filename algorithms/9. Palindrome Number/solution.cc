class Solution {
public:
    bool isPalindrome(int x) {
        long sum = 0;
        int n = x;
        while ( n > 0 ) {
            sum = sum * 10 + n % 10;
            n /= 10;
        }
        return x == sum;
    }
};

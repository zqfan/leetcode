class Solution {
public:
    bool isHappy(int n) {
        // @Freezen
        int fast = n, slow = n;
        do {
            slow = getDigitsSquareSum(slow);
            fast = getDigitsSquareSum(fast);
            fast = getDigitsSquareSum(fast);
        } while ( slow != fast );
        return slow == 1;
    }

    int getDigitsSquareSum(int n) {
        int sum = 0, last;
        while ( n > 0 ) {
            last = n % 10;
            sum += last * last;
            n /= 10;
        }
        return sum;
    }
};

// 401 / 401 test cases passed.
// Status: Accepted
// Runtime: 3 ms

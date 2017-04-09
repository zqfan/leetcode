class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

// 21038 / 21038 test cases passed.
// Status: Accepted
// Runtime: 65 ms
// beats 32.10%

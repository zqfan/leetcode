class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        next_permutation(digits.begin(), digits.end());
        long long result = stoll(digits);
        return result > 0x7fffffff || result <= n ? -1 : result;
    }
};

// 34 / 34 test cases passed.
// Status: Accepted
// Runtime: 3 ms

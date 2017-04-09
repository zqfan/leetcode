class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while ( n > 1 && visited.find(n) == visited.end() ) {
            visited.insert(n);
            n = getDigitsSquareSum(n);
        }
        return n == 1;
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
// beats 19.52%

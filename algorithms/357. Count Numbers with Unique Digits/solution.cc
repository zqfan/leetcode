class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count = 1, product = 1, limit = min(n, 10);
        vector<int> choices = {9, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        for ( int i = 0; i < limit; ++i ) {
            product *= choices[i];
            count += product;
        }
        return count;
    }
};

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n1 = 1001, n2 = 1001, m1 = -1001, m2 = -1001, m3 = -1001;
        for ( int n : nums ) {
            if ( n >= m1 ) {
                m3 = m2;
                m2 = m1;
                m1 = n;
            } else if ( n >= m2 ) {
                m3 = m2;
                m2 = n;
            } else if ( n > m3 ) {
                m3 = n;
            }

            if ( n <= n1 ) {
                n2 = n1;
                n1 = n;
            } else if ( n < n2 ) {
                n2 = n;
            }
        }
        return max(n1 * n2 * m1, m1 * m2 * m3);
    }
};

// 83 / 83 test cases passed.
// Status: Accepted
// Runtime: 49 ms
